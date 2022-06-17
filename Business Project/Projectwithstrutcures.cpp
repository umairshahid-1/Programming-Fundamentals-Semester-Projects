#include <iostream>  //input,output
#include <conio.h>   //clearscreen,getch
#include <stdlib.h>  //getch
#include <windows.h> //gotoxy
#include <fstream>   //filehandling
using namespace std;

//********************************************** Proto Types **********************************************
void clearscreen();
void gotoxy(int x, int y);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Colour Function
void mainHeader();
char Entering();

struct products
{
  string productNames;
  float quantities;
  float purchasePrices;
  float sellingPrices;
};

struct employees
{
  string ids;
  string passWords;
};

struct customers
{
  string customersNames;
  string customersPasswords;
};

// Functions for Admin
string Admin_Entering();
char Retype_Passwords();
int Admin_Menu();

// Function for Viewing Stock in Sorting Order
void View_Stock_Header();
char Sorting_Order();
int Smallest(products data[], int arrayCount, int position);
int Largest(products data[], int arrayCount, int position);
void Sorting1(products data[], int arrayCount);
void Sorting2(products data[], int arrayCount);

// Function for Adding New Employees
void Add_Employees_Header(employees emplData[], int &employeeCount);
void Add_Employees_Record_In_Array(employees emplData[], employees info, int &employeeCount);

// Function for Leaving message for Employees
string Leaving_Message();

// Functions for Employees
bool Employee_Entering(employees emplData[], int employeeCount);
bool Checking(employees emplData[], employees info, int employeeCount);
int Employee_Menu();

// Functions for Adding Stock
void Display_Stock_Header();
void Add_Stock_Header(products data[], int &productCount);
void Input_Data(products data[], int &productCount);
void Add_Stock_In_Array(products data[], products info, int &productCount);
void Array_Data(products data[], int &arrayCount);

// Functions for Updating Stock
void Update_Stock_Header();
void Update(products data[], int option);
void Updating_Data(products data[], int &arrayCount);

// Function for Deleting Stock
void Delete_Stock_Header();
void Delete(products data[], int &arrayCount, int option);
void Deleting_Data(products data[], int &arrayCount);

// Function for Reading Message
void Reading_Message(string Message);

// Function for Customers
void Customer_SignUp(customers custData[], int &customerCount);
void Add_Customers_Record_In_Array(customers custData[], customers info, int customerCount);

bool Customer_SignIn(customers custData[], int customerCount);
bool Customer_Checking(customers custData[], customers info, int customerCount);
int Customer_Menu();

// Function for Add Prodcuts to Cart
void add_products_to_cart(string Product_Names[], float Quantities[], float Selling_Prices[], int arrayCount);
int load_for_shoping(string Product_Names[], float Quantities[], float Selling_Prices[]);
void array_data_for_shoping(string Product_Names[], float Quantities[], float Selling_Prices[], int arrayCount);
void display_stock_header_for_Shoping();
void addtoCart(int arrayCount);

// File Handling
void store(products data[], int productCount);
void Updatefile(products data[], int arrayCount);
void Employees_Data_Store(employees emplData[], int employeeCount);
void Customers_Data_Store(customers custData[], int customerCount);
string parseData(string record, int field);
int load(products data[]);
int Employees_Data_Load(employees emplData[]);
int Customers_Data_Load(customers custData[]);

main() // **********************************************  Main **********************************************
{
  // Local Arrays, Datastructures for Adding Stock
  const int records = 20;
  products data[records];
  int productCount = load(data);

  // Reading from File
  int arrayCount = load(data);

  // Local Arrays, Datastructures for Adding Employees
  int employeeCount = 0;
  employees emplData[records];

  // Local Arrays, Datastructures for Customers Sign Up
  int customerCount = 0;
  customers custData[records];

  // Reading Admin message
  string Message = "";

  system("CLS");
  while (true) // Main While loop If the Entering Option is wrong than it will continue to run , Like in Admin Enetring option
  {
    char Main_Option = Entering(); // Checking that who is entering

    if (Main_Option == '1') // At 1 there is Admin
    {
      while (true) // Incase if user want to return to main menu then this while loop will break
      {
        system("CLS");
        string Password = Admin_Entering();

        if (Password == "1234") // if Password match than do this
        {
          system("CLS");
          while (true)
          {
            int Option = 1;

            while (Option != 0)
            {
              Option = Admin_Menu(); // Here admin select what to do
              system("CLS");

              if (Option == 1) // View Stock
              {
                char Option = '0';
                Option = Sorting_Order(); // Ask in which do you want to see the sorting with quantity based

                system("CLS");
                View_Stock_Header();
                arrayCount = load(data);

                if (Option == '1') // Assending
                {
                  Sorting1(data, arrayCount);
                  Array_Data(data, arrayCount);
                }

                else if (Option == '2') // Decesending
                {
                  Sorting2(data, arrayCount);
                  Array_Data(data, arrayCount);
                }
                Updatefile(data, arrayCount);
                system("CLS");
              }

              else if (Option == 2) // Add New Employees
              {
                Add_Employees_Header(emplData, employeeCount);
                Employees_Data_Store(emplData, employeeCount);
              }

              else if (Option == 3) // Gross Income
              {
                Message = Leaving_Message();
                // cout << "Gross Income" << endl;
              }

              else if (Option == 4) // Transfer Salaries
              {
                cout << "Transfer Salaries" << endl;
              }

              else if (Option == 5) // Pay Bills
              {
                cout << "Pay Bills";
              }

              else if (Option == 6) // Total Profit
              {
                cout << "Total Profit";
              }

              else if (Option == 7) // History of Sales
              {
                cout << "History of Sales";
              }

              else if (Option == 8) // Offer Discount
              {
                cout << "Offer Discount";
              }

              else if (Option == 9) // Leave Message
              {
                // Message = Leaving_Message();
              }

              else if (Option != 0) // Incase of wrong option in Admin Menu
              {
                SetConsoleTextAttribute(hConsole, 4); // Red
                gotoxy(30, 0);
                cout << "-------------------";
                gotoxy(30, 1);
                cout << "  **** Admin ****  ";
                gotoxy(30, 2);
                cout << "-------------------";

                SetConsoleTextAttribute(hConsole, 7); // White
                gotoxy(0, 4);
                cout << "You Enter a Wrong Number! ";

                getch();
                system("CLS");
              }
            }

            break; // if Option ==  0
          }
          break;                     // if Option ==  0,Return to Main Menu
        }                            // if Password is correct
        else if (Password != "1234") // if Admin password is incorrect then
        {
          char Option = Retype_Passwords();

          if (Option == '1')
          {
            SetConsoleTextAttribute(hConsole, 8); // Gray
            cout << "Press any key to continue...";
            getch();
          }
          else if (Option == '2')
          {
            system("CLS");
            break;
          }
        }
      }
    }

    else if (Main_Option == '2') // At 2 there are Employees
    {
      while (true) // Incase if user want to return to main menu then this while loop will break
      {
        system("CLS");
        employeeCount = Employees_Data_Load(emplData);
        bool check = true;
        check = Employee_Entering(emplData, employeeCount);

        if (check == true) // if Id and Passwords are correct then do this
        {
          system("CLS");
          while (true)
          {
            int Option = 1;

            while (Option != 0)
            {
              Option = Employee_Menu(); // Here Employee select what to do
              system("CLS");

              if (Option == 1) // Add_Product
              {
                if (productCount > records) // if Products which is added is greater than records than this
                {
                  cout << "No more Space! " << endl;
                  getch();
                  system("CLS");
                  break;
                }

                Add_Stock_Header(data, productCount);
                store(data, productCount); // store data in file
              }

              else if (Option == 2) // Update Stock
              {
                Update_Stock_Header();
                arrayCount = load(data);
                Updating_Data(data, arrayCount);
                Updatefile(data, arrayCount);
              }

              else if (Option == 3) // Delete Stock
              {
                Delete_Stock_Header();
                arrayCount = load(data);
                Deleting_Data(data, arrayCount);
                Updatefile(data, arrayCount);
              }

              else if (Option == 4) // View Stock
              {
                char Option = '0';
                Option = Sorting_Order(); // Ask in which do you want to see the sorting with quantity based

                system("CLS");
                View_Stock_Header();
                arrayCount = load(data);

                if (Option == '1') // Assending
                {
                  Sorting1(data, arrayCount);
                  Array_Data(data, arrayCount);
                }

                else if (Option == '2') // Decesending
                {
                  Sorting2(data, arrayCount);
                  Array_Data(data, arrayCount);
                }
                Updatefile(data, arrayCount);
                system("CLS");
              }

              else if (Option == 5) // Sale Products
              {
                cout << "Sale Poducts";
              }

              else if (Option == 6) // Reading Message
              {
                Reading_Message(Message);
              }

              else if (Option != 0) // Incase of wrong option in Employee Menu
              {
                SetConsoleTextAttribute(hConsole, 4); // Red
                gotoxy(30, 0);
                cout << "-------------------";
                gotoxy(30, 1);
                cout << "**** Employees ****";
                gotoxy(30, 2);
                cout << "-------------------";

                SetConsoleTextAttribute(hConsole, 7); // White
                gotoxy(0, 4);
                cout << "You Enter a Wrong Number! ";

                getch();
                system("CLS");
              }
            }

            break; // if Option ==  0
          }
          break; // if Option ==  0,Return to Main Menu
        }

        else if (check != true) // if Id and Passwords are incorrect then do this
        {
          char Option = Retype_Passwords();

          if (Option == '1')
          {
            SetConsoleTextAttribute(hConsole, 8); // Gray
            cout << "Press any key to continue...";
            getch();
          }
          else if (Option == '2')
          {
            system("CLS");
            break;
          }
        }
      }
    }

    else if (Main_Option == '3') // At 3 there is Customer
    {
      while (true) // Incase if user want to return to main menu then this while loop will break
      {
        system("CLS");
        customerCount = Customers_Data_Load(custData);
        bool check = true;
        check = Customer_SignIn(custData, customerCount);

        if (check == true) // if Id and Passwords are correct then do this
        {
          system("CLS");
          while (true)
          {
            int Option = 1;

            while (Option != 0)
            {
              Option = Customer_Menu(); // Here Customers can select what to do
              system("CLS");

              if (Option == 1) // Add Products to cart
              {
                display_stock_header_for_Shoping();
                // arrayCount = load_for_shoping(Product_Names, Quantities, Selling_Prices);
                // array_data_for_shoping(Product_Names, Quantities, Selling_Prices, arrayCount);
              }

              else if (Option != 0) // Incase of wrong option in Customers Menu
              {
                SetConsoleTextAttribute(hConsole, 4); // Red
                gotoxy(30, 0);
                cout << "-------------------";
                gotoxy(30, 1);
                cout << "**** CUSTOMERS ****";
                gotoxy(30, 2);
                cout << "-------------------";

                SetConsoleTextAttribute(hConsole, 7); // White
                gotoxy(0, 4);
                cout << "You Enter a Wrong Number! ";

                getch();
                system("CLS");
              }
            }

            break; // if Option ==  0
          }
          break; // if Option ==  0,Return to Main Menu
        }

        else if (check != true) // if Id and Passwords are incorrect then do this
        {
          char Option = Retype_Passwords();

          if (Option == '1')
          {
            SetConsoleTextAttribute(hConsole, 8); // Gray
            cout << "Press any key to continue...";
            getch();
          }
          else if (Option == '2')
          {
            system("CLS");
            break;
          }
        }
      }
    }

    else if (Main_Option == '4') // At 4 Customers can sign up
    {
      Customer_SignUp(custData, customerCount);
      Customers_Data_Store(custData, customerCount);
    }

    else if (Main_Option == '5') // At 5 Exit
    {
      system("CLS");
      mainHeader();
      cout << "\n";
      SetConsoleTextAttribute(hConsole, 7);
      cout << "Thanks for using this Applicatin! " << endl;
      break;
    } // Main Exit from Function

    else
    {
      system("CLS");
      mainHeader();
      cout << "\n";
      SetConsoleTextAttribute(hConsole, 4); // Red
      cout << "You Enter a Wrong Number! " << endl;
      SetConsoleTextAttribute(hConsole, 7); // White
      clearscreen();
    } // Incase of wrong option in Main Options
  }   // End Main While
} // End Main

// **********************************************  Function Definations **********************************************

void clearscreen() // Function for clear screen
{
  cout << "Press any key to continue...";
  getch();
  system("CLS");
}

void gotoxy(int x, int y) // function to use for going on specfic Position on console
{
  COORD coordinates; // coordinates is declared as COORD
  coordinates.X = x; // defining x-axis
  coordinates.Y = y; // defining  y-axis
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void mainHeader()
{
  SetConsoleTextAttribute(hConsole, 6); // yellow
  cout << "   _____                          __  ___           __        __                                       " << endl;
  cout << "  / ___/__  ______  ___  _____   /  |/  /___ ______/ /_____  / /_                                      " << endl;
  cout << "  \\__ \\/ / / / __ \\/ _ \\/ ___/  / /|_/ / __ `/ ___/ //_/ _ \\/ __/                                      " << endl;
  cout << " ___/ / /_/ / /_/ /  __/ /     / /  / / /_/ / /  / ,< /  __/ /_                                        " << endl;
  cout << "/____/\\__,_/ .___/\\___/_/     /_/  /_/\\__,_/_/  /_/|_|\\___/\\__/                                        " << endl;
  cout << "          /_/                                                                                          " << endl;
  cout << "    __  ___                                                  __     _____            __                " << endl;
  cout << "   /  |/  /___ _____  ____ _____ ____  ____ ___  ___  ____  / /_   / ___/__  _______/ /____  ____ ___  " << endl;
  cout << "  / /|_/ / __ `/ __ \\/ __ `/ __ `/ _ \\/ __ `__ \\/ _ \\/ __ \\/ __/   \\__ \\/ / / / ___/ __/ _ \\/ __ `__ \\ " << endl;
  cout << " / /  / / /_/ / / / / /_/ / /_/ /  __/ / / / / /  __/ / / / /_    ___/ / /_/ (__  ) /_/  __/ / / / / / " << endl;
  cout << "/_/  /_/\\__,_/_/ /_/\\__,_/\\__, /\\___/_/ /_/ /_/\\___/_/ /_/\\__/   /____/\\__, /____/\\__/\\___/_/ /_/ /_/  " << endl;
  cout << "                         /____/                                       /____/                           " << endl;
}

char Entering() // Who Is Entering
{
  mainHeader();
  SetConsoleTextAttribute(hConsole, 2); // Green
  cout << endl;
  cout << "Select one of the following option number..." << endl;
  cout << endl;
  cout << "1. Admin" << endl;
  cout << "2. Employees" << endl;
  cout << "3. Customers" << endl;
  cout << "4. Customers SignUp" << endl;
  cout << "5. Exit" << endl;
  cout << endl;

  char Op;
  SetConsoleTextAttribute(hConsole, 4); // Red
  cout << "Your Option: ";
  SetConsoleTextAttribute(hConsole, 7); // White
  cin >> Op;

  return Op;
}

//************ Admin ************

string Admin_Entering() // Admin password enetring headrer and return Password for checking
{
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(30, 0);
  cout << "-------------------";
  gotoxy(30, 1);
  cout << "  **** Admin ****  ";
  gotoxy(30, 2);
  cout << "-------------------";

  string Password;
  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(0, 4);
  cout << "Admin Enter Password: ";
  SetConsoleTextAttribute(hConsole, 7); // white
  cin >> Password;

  return Password;
}

char Retype_Passwords() // Fuunction if the Password or Ids entered is wrong
{
  cout << endl;
  SetConsoleTextAttribute(hConsole, 4); // Red
  cout << "Wrong Input!" << endl;
  cout << endl;

  SetConsoleTextAttribute(hConsole, 2); // Green
  cout << "1. Retype..." << endl;
  cout << "2. Return to Main Menu..." << endl;

  SetConsoleTextAttribute(hConsole, 3); // Aqua
  cout << endl;
  cout << "Enter your Option: ";

  char Opt;
  SetConsoleTextAttribute(hConsole, 7); // White
  cin >> Opt;

  return Opt;
}

int Admin_Menu() // Menu Function for Admin , Select a option what to do and to return to main
{
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(30, 0);
  cout << "-------------------";
  gotoxy(30, 1);
  cout << "  **** ADMIN ****  ";
  gotoxy(30, 2);
  cout << "-------------------";

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(0, 4);
  cout << "Select one of the following option number..." << endl;

  SetConsoleTextAttribute(hConsole, 2); // Green
  cout << "<1> View Stock " << endl;
  cout << "<2> Add New Employees " << endl;
  cout << "<3> Leave Message" << endl;
  cout << "<4> Transfer Salaries " << endl;
  cout << "<5> Pay Bills " << endl;
  cout << "<6> Total Profit " << endl;
  cout << "<7> History of Sales " << endl;
  cout << "<8> Offer Discount " << endl;
  cout << "<9> Gross Income" << endl;
  cout << "<0> Log Out" << endl;

  SetConsoleTextAttribute(hConsole, 3); // Aqua
  gotoxy(0, 16);
  cout << "Your Option: ";

  int Opt;
  SetConsoleTextAttribute(hConsole, 7); // White
  cin >> Opt;

  return Opt;
}

void View_Stock_Header() // Function Declaration For View Stock Header
{
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(40, 0);
  cout << "-------------------";
  gotoxy(40, 1);
  cout << "  **** Admin ****  ";
  gotoxy(40, 2);
  cout << "-------------------";
  SetConsoleTextAttribute(hConsole, 3); // Aqua
  gotoxy(40, 4);
  cout << "     VIEW STOCK";

  Display_Stock_Header();
}

char Sorting_Order() // Function to ask for which order user wanted to see the Products
{
  SetConsoleTextAttribute(hConsole, 4);
  gotoxy(30, 0);
  cout << "-------------------" << endl;
  gotoxy(30, 1);
  cout << "  **** Admin ****  " << endl;
  gotoxy(30, 2);
  cout << "-------------------" << endl;
  SetConsoleTextAttribute(hConsole, 3);
  gotoxy(30, 4);
  cout << "     VIEW STOCK" << endl;

  char Option = 0;
  gotoxy(0, 6);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "You can View stock in these Order...";
  gotoxy(0, 7);
  SetConsoleTextAttribute(hConsole, 7);
  cout << "1. Assending Order " << endl;
  cout << "2. Desending Order " << endl;

  gotoxy(0, 10);
  SetConsoleTextAttribute(hConsole, 3);
  cout << "Your Option: ";
  SetConsoleTextAttribute(hConsole, 7);
  cin >> Option;

  return Option;
}

int Smallest(products data[], int arrayCount, int position) // find the Index where there is smallest Number in the Array for Asending order sorting
{
  int index = position;
  float temp = data[position].quantities;

  for (int x = position; x < arrayCount; x++)
  {
    if (temp > data[x].quantities)
    {
      temp = data[x].quantities;
      index = x;
    }
  }

  return index;
}

int Largest(products data[], int arrayCount, int position) // find the Index where there is Largest Number in the Array for Descending order sorting
{
  int index = position;
  float temp = data[position].quantities;

  for (int x = position; x < arrayCount; x++)
  {
    if (temp < data[x].quantities)
    {
      temp = data[x].quantities;
      index = x;
    }
  }

  return index;
}

void Sorting1(products data[], int arrayCount)
{
  for (int x = 0; x < arrayCount; x++)
  {
    int ind = Smallest(data, arrayCount, x);

    products temp = data[x];
    data[x] = data[ind];
    data[ind] = temp;
  }
}

void Sorting2(products data[], int arrayCount)
{
  for (int x = 0; x < arrayCount; x++)
  {
    int ind = Largest(data, arrayCount, x);

    products temp = data[x];
    data[x] = data[ind];
    data[ind] = temp;
  }
}

void Add_Employees_Header(employees emplData[], int &employeeCount) // Functon for Adding Employees
{
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(40, 0);
  cout << "------------------";
  gotoxy(40, 1);
  cout << "  **** Admin **** ";
  gotoxy(40, 2);
  cout << "------------------";
  SetConsoleTextAttribute(hConsole, 3); // Aqua
  gotoxy(40, 4);
  cout << " ADD NEW EMPLOYEES";

  employees info;

  SetConsoleTextAttribute(hConsole, 6);
  gotoxy(0, 7);
  cout << "Enter the ID of the Employee: ";
  gotoxy(0, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin.ignore();
  getline(cin, info.ids);

  gotoxy(45, 7);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Assign Password: ";
  gotoxy(45, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin >> info.passWords;

  Add_Employees_Record_In_Array(emplData, info, employeeCount);
  employeeCount++;

  system("CLS");
}

void Add_Employees_Record_In_Array(employees emplData[], employees info, int &employeeCount)
{
  emplData[employeeCount] = info; // Function For Adding Employees Data from variable to Array
}

string Leaving_Message() // Function Header for Leaving Message
{
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(40, 0);
  cout << "------------------";
  gotoxy(40, 1);
  cout << "  **** Admin **** ";
  gotoxy(40, 2);
  cout << "------------------";
  SetConsoleTextAttribute(hConsole, 3); // Aqua
  gotoxy(40, 4);
  cout << "  Leave Messages";

  string Message;
  SetConsoleTextAttribute(hConsole, 6);
  gotoxy(0, 7);
  cout << "Write the Message Here: ";
  gotoxy(24, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin.ignore();

  getline(cin, Message);
  system("CLS");

  return Message;
}

// //************ Employees ************
bool Employee_Entering(employees emplData[], int employeeCount) // Employee entering Assigned Id and Password
{
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(30, 0);
  cout << "-------------------";
  gotoxy(30, 1);
  cout << "**** Employees ****";
  gotoxy(30, 2);
  cout << "-------------------";

  employees info;

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(0, 4);
  cout << "Enter Your Id: ";
  SetConsoleTextAttribute(hConsole, 7); // white
  gotoxy(0, 6);
  cin.ignore();
  getline(cin, info.ids);

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(30, 4);
  cout << "Enter Your Password: ";
  SetConsoleTextAttribute(hConsole, 7); // white
  gotoxy(30, 6);
  getline(cin, info.passWords);

  bool flag = true;
  flag = Checking(emplData, info, employeeCount);
  return flag;
}

bool Checking(employees emplData[], employees info, int employeeCount)
{
  for (int x = 0; x < employeeCount; x++)
  {
    if (emplData[x].ids == info.ids && emplData[x].passWords == info.passWords)
    {
      return true;
    }
  }
  return false;
}

int Employee_Menu() // Menu Function for Employee , Select a option what to do and to return to main
{
  SetConsoleTextAttribute(hConsole, 6); // Red
  gotoxy(30, 0);
  cout << "-------------------";
  gotoxy(30, 1);
  cout << "**** Employees ****";
  gotoxy(30, 2);
  cout << "-------------------";

  SetConsoleTextAttribute(hConsole, 4); // Yellow
  gotoxy(0, 4);
  cout << "Select one of the following option number..." << endl;

  SetConsoleTextAttribute(hConsole, 2); // Green
  cout << "<1> Add Stock " << endl;
  cout << "<2> Update Stock " << endl;
  cout << "<3> Delete Stock " << endl;
  cout << "<4> View Stock " << endl;
  cout << "<5> Sale Products " << endl;
  cout << "<6> Check Admin Message " << endl;
  cout << "<7> View and Maintain Stock " << endl;
  cout << "<0> Log Out" << endl;

  SetConsoleTextAttribute(hConsole, 3); // Aqua
  gotoxy(0, 14);
  cout << "Your Option: ";

  int Opt;
  SetConsoleTextAttribute(hConsole, 7); // White
  cin >> Opt;

  return Opt;
}

void Display_Stock_Header() // function for just display
{
  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(0, 7);
  cout << "Sr.No";
  gotoxy(20, 7);
  cout << "Product_Name";
  gotoxy(47, 7);
  cout << "Quantity";
  gotoxy(70, 7);
  cout << "Purchasing_Price";
  gotoxy(101, 7);
  cout << "Selling_Price";

  SetConsoleTextAttribute(hConsole, 7); // White
}

void Add_Stock_Header(products data[], int &productCount)
{
  SetConsoleTextAttribute(hConsole, 4);
  gotoxy(50, 0);
  cout << "--------------------" << endl;
  gotoxy(50, 1);
  cout << " **** EMPLOYEE **** " << endl;
  gotoxy(50, 2);
  cout << "--------------------" << endl;
  SetConsoleTextAttribute(hConsole, 3);
  gotoxy(50, 4);
  cout << "     ADD STOCK" << endl;

  Input_Data(data, productCount);
  system("CLS");
}

void Input_Data(products data[], int &productCount) // Function for taking Input
{
  products info;

  SetConsoleTextAttribute(hConsole, 6);
  gotoxy(0, 7);
  cout << "Name of Products";
  gotoxy(0, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin.ignore();
  getline(cin, info.productNames);

  gotoxy(31, 7);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Quantity of Products";
  gotoxy(31, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin >> info.quantities;

  gotoxy(66, 7);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Purchasing price";
  gotoxy(66, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin >> info.purchasePrices;

  gotoxy(97, 7);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Selling Price";
  gotoxy(97, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin >> info.sellingPrices;

  Add_Stock_In_Array(data, info, productCount);
  productCount++;
}

void Add_Stock_In_Array(products data[], products info, int &productCount)
{
  data[productCount] = info;
}

void Array_Data(products data[], int &arrayCount) // Displaying the Data of the Array
{
  int y = 9;
  for (int x = 0; x < arrayCount; x++)
  {
    gotoxy(0, y);
    cout << x + 1;
    gotoxy(20, y);
    cout << data[x].productNames;
    gotoxy(47, y);
    cout << data[x].quantities;
    gotoxy(70, y);
    cout << data[x].purchasePrices;
    gotoxy(101, y);
    cout << data[x].sellingPrices;
    y++;
  }
  getch();
  system("CLS");
}

void Update_Stock_Header() // Function Declaration For Updating Stock Header
{
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(42, 0);
  cout << "--------------------";
  gotoxy(42, 1);
  cout << " **** EMPLOYEE **** ";
  gotoxy(42, 2);
  cout << "--------------------";
  SetConsoleTextAttribute(hConsole, 3); // Aqua
  gotoxy(42, 4);
  cout << "   UPDATE STOCK";

  Display_Stock_Header();
}

void Update(products data[], int option) // Function for Update the Stock
{
  products info;

  cout << endl;
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Name of the Product : ";
  SetConsoleTextAttribute(hConsole, 7);
  cin.ignore();
  getline(cin, info.productNames);

  SetConsoleTextAttribute(hConsole, 6);
  cout << "Quantity of Product : ";
  SetConsoleTextAttribute(hConsole, 7);
  cin >> info.quantities;

  SetConsoleTextAttribute(hConsole, 6);
  cout << "Purchasing price : ";
  SetConsoleTextAttribute(hConsole, 7);
  cin >> info.purchasePrices;

  SetConsoleTextAttribute(hConsole, 6);
  cout << "Selling Price : ";
  SetConsoleTextAttribute(hConsole, 7);
  cin >> info.sellingPrices;

  data[option - 1] = info;
}

void Updating_Data(products data[], int &arrayCount) // Array before updating , Displaying the Array
{
  int y = 9;
  for (int x = 0; x < arrayCount; x++)
  {
    gotoxy(0, y);
    cout << x + 1;
    gotoxy(20, y);
    cout << data[x].productNames;
    gotoxy(47, y);
    cout << data[x].quantities;
    gotoxy(70, y);
    cout << data[x].purchasePrices;
    gotoxy(101, y);
    cout << data[x].sellingPrices;
    y++;
  }

  int option = 1;
  gotoxy(0, y + 1);
  SetConsoleTextAttribute(hConsole, 4); // Red
  cout << "Enter your Option: ";
  SetConsoleTextAttribute(hConsole, 7); // White
  cin >> option;

  if (option > 0)
  {
    Update(data, option);

    gotoxy(40, y + 8);
    SetConsoleTextAttribute(hConsole, 4); // Red
    cout << "Updated Successfully!";

    getch();
  }
  system("CLS");
}

void Delete_Stock_Header() // Function Declaration For Deleting Stock Header
{
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(42, 0);
  cout << "--------------------";
  gotoxy(42, 1);
  cout << " **** EMPLOYEE **** ";
  gotoxy(42, 2);
  cout << "--------------------";
  SetConsoleTextAttribute(hConsole, 3); // Aqua
  gotoxy(42, 4);
  cout << "   DELETE STOCK";

  Display_Stock_Header();
}

void Delete(products data[], int &arrayCount, int option) // Actual Function for Deleting the Data from the Array
{
  if (arrayCount > 0)
  {
    for (int x = option - 1; x < arrayCount - 1; x++)
    {
      data[x] = data[x + 1];
    }

    arrayCount--; // Because after Deletition , Size of the Array will be decrease
  }
}

void Deleting_Data(products data[], int &arrayCount) // Array before Deleting , Displaying the Array
{
  int y = 9;
  for (int x = 0; x < arrayCount; x++)
  {
    gotoxy(0, y);
    cout << x + 1;
    gotoxy(20, y);
    cout << data[x].productNames;
    gotoxy(47, y);
    cout << data[x].quantities;
    gotoxy(70, y);
    cout << data[x].purchasePrices;
    gotoxy(101, y);
    cout << data[x].sellingPrices;
    y++;
  }

  int option = 1;
  gotoxy(0, y + 1);
  SetConsoleTextAttribute(hConsole, 4); // Red
  cout << "Enter your Option: ";
  SetConsoleTextAttribute(hConsole, 7); // White
  cin >> option;

  if (option > 0)
  {
    Delete(data, arrayCount, option);

    gotoxy(40, y + 3);
    SetConsoleTextAttribute(hConsole, 4); // Red
    cout << "Dleted Successfuly!";

    getch();
  }

  system("CLS");
}

void Reading_Message(string Message) // Function Header for Reading Message
{
  SetConsoleTextAttribute(hConsole, 3); // Aqua
  gotoxy(40, 0);
  cout << "--------------------";
  gotoxy(40, 1);
  cout << " **** EMPLOYEE **** ";
  gotoxy(40, 2);
  cout << "--------------------";
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(40, 4);
  cout << "    Read Messages";

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(0, 6);
  cout << "MESSAGE:";

  SetConsoleTextAttribute(hConsole, 8); // Gray
  gotoxy(8, 8);
  cout << Message;
  getch();
  system("CLS");
}

//************ Customer SignUP ************

void Customer_SignUp(customers custData[], int &customerCount) // Function for Customers Signup
{
  system("CLS");
  SetConsoleTextAttribute(hConsole, 3); // Aqua
  gotoxy(40, 0);
  cout << "---------------------";
  gotoxy(40, 1);
  cout << " **** CUSTOMERS **** ";
  gotoxy(40, 2);
  cout << "---------------------";
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(40, 4);
  cout << "       SIGN UP";

  customers info;
  string Retype_Password;

  SetConsoleTextAttribute(hConsole, 6);
  gotoxy(0, 7);
  cout << "Enter Your Name:";
  gotoxy(16, 8);
  SetConsoleTextAttribute(hConsole, 7);
  cin.ignore();
  getline(cin, info.customersNames);

  gotoxy(0, 10);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Enter the Password:";
  gotoxy(19, 11);
  SetConsoleTextAttribute(hConsole, 7);
  cin >> info.customersPasswords;

  gotoxy(0, 13);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Retype the Password:";
  gotoxy(20, 14);
  SetConsoleTextAttribute(hConsole, 7);
  cin >> Retype_Password;

  if (info.customersPasswords == Retype_Password)
  {
    Add_Customers_Record_In_Array(custData, info, customerCount);
    customerCount++;

    gotoxy(40, 16);
    SetConsoleTextAttribute(hConsole, 4); // Red
    cout << "SignUp Successfully!";
    getch();
  }
  // else // incase if retype Password is incorrect then do this
  // {
  // }
  system("CLS");
}

void Add_Customers_Record_In_Array(customers custData[], customers info, int customerCount)
{
  custData[customerCount] = info; // Function For Adding Employees Data from variable to Array
}

//************ Customer SignIn ************

bool Customer_SignIn(customers custData[], int customerCount) // for customers SignIn
{
  system("CLS");
  SetConsoleTextAttribute(hConsole, 3); // Aqua
  gotoxy(40, 0);
  cout << "---------------------";
  gotoxy(40, 1);
  cout << " **** CUSTOMERS **** ";
  gotoxy(40, 2);
  cout << "---------------------";
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(40, 4);
  cout << "       SIGN IN";

  customers info;

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(0, 6);
  cout << "Enter Your Name: ";
  SetConsoleTextAttribute(hConsole, 7); // white
  gotoxy(0, 8);
  cin.ignore();
  getline(cin, info.customersNames);

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(30, 6);
  cout << "Enter Your Password: ";
  SetConsoleTextAttribute(hConsole, 7); // white
  gotoxy(30, 8);
  getline(cin, info.customersPasswords);

  bool flag = true;
  flag = Customer_Checking(custData, info, customerCount);
  return flag;
}

bool Customer_Checking(customers custData[], customers info, int customerCount)
{
  for (int x = 0; x < customerCount; x++)
  {
    if (custData[x].customersNames == info.customersNames && custData[x].customersPasswords == info.customersPasswords)
    {
      return true;
    }
  }
  return false;
}

int Customer_Menu() // Menu Function for Customer , Select a option what to do and to return to main
{
  SetConsoleTextAttribute(hConsole, 3); // Aqua
  gotoxy(30, 0);
  cout << "-------------------";
  gotoxy(30, 1);
  cout << "**** CUSTOMERS ****";
  gotoxy(30, 2);
  cout << "-------------------";

  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(0, 4);
  cout << "Select one of the following option number..." << endl;

  SetConsoleTextAttribute(hConsole, 2); // Green
  cout << "<1> Add Products to Cart " << endl;
  cout << "<2> View Discounted Products " << endl;
  cout << "<0> Log Out" << endl;

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(0, 9);
  cout << "Your Option: ";

  int Opt;
  SetConsoleTextAttribute(hConsole, 7); // White
  cin >> Opt;

  return Opt;
}

//************ File Handling ************

void store(products data[], int productCount)
{
  fstream myFile;
  myFile.open("Stock.txt", ios::app);
  for (int x = productCount - 1; x < productCount; x++)
  {
    myFile << data[x].productNames << "," << data[x].quantities << "," << data[x].purchasePrices << "," << data[x].sellingPrices << endl;
  }
  myFile.close();
}

void Updatefile(products data[], int arrayCount)
{
  fstream myFile;
  myFile.open("Stock.txt", ios::out);
  for (int x = 0; x < arrayCount; x++)
  {
    myFile << data[x].productNames << "," << data[x].quantities << "," << data[x].purchasePrices << "," << data[x].sellingPrices << endl;
  }
  myFile.close();
}

string parseData(string record, int field)
{
  int comma = 1;
  string item;
  for (int x = 0; x < record.length(); x++)
  {
    if (record[x] == ',')
    {
      comma = comma + 1;
    }
    else if (comma == field)
    {
      item = item + record[x];
    }
  }
  return item;
}

int load(products data[])
{
  fstream f;
  string record;
  int idx = 0;
  f.open("Stock.txt", ios::in);
  while (!(f.eof()))
  {
    getline(f, record);
    if (record != "")
    {
      data[idx].productNames = parseData(record, 1);
      data[idx].quantities = stof(parseData(record, 2));
      data[idx].purchasePrices = stof(parseData(record, 3));
      data[idx].sellingPrices = stof(parseData(record, 4));
      idx++;
    }
  }
  f.close();
  return idx;
}

void Employees_Data_Store(employees emplData[], int employeeCount)
{
  fstream myFile;
  myFile.open("Employees.txt", ios::app);
  for (int x = employeeCount - 1; x < employeeCount; x++)
  {
    myFile << emplData[x].ids << "," << emplData[x].passWords << endl;
  }
  myFile.close();
}

int Employees_Data_Load(employees emplData[])
{
  fstream f;
  string record;
  int idx = 0;
  f.open("Employees.txt", ios::in);
  while (!(f.eof()))
  {
    getline(f, record);
    if (record != "")
    {
      emplData[idx].ids = parseData(record, 1);
      emplData[idx].passWords = parseData(record, 2);
      idx++;
    }
  }
  f.close();
  return idx;
}

void Customers_Data_Store(customers custData[], int customerCount)
{
  fstream myFile;
  myFile.open("Customers.txt", ios::app);
  for (int x = customerCount - 1; x < customerCount; x++)
  {
    myFile << custData[x].customersNames << "," << custData[x].customersPasswords << endl;
  }
  myFile.close();
}

int Customers_Data_Load(customers custData[])
{
  fstream f;
  string record;
  int idx = 0;
  f.open("Customers.txt", ios::in);
  while (!(f.eof()))
  {
    getline(f, record);
    if (record != "")
    {
      custData[idx].customersNames = parseData(record, 1);
      custData[idx].customersPasswords = parseData(record, 2);
      idx++;
    }
  }
  f.close();
  return idx;
}

void add_products_to_cart(string Product_Names[], float Quantities[], float Selling_Prices[], int arrayCount)
{
  arrayCount = load_for_shoping(Product_Names, Quantities, Selling_Prices);
  array_data_for_shoping(Product_Names, Quantities, Selling_Prices, arrayCount);
}

void array_data_for_shoping(string Product_Names[], float Quantities[], float Selling_Prices[], int arrayCount) // Displaying the Data of the Array
{
  int y = 9;
  for (int x = 0; x < arrayCount; x++)
  {
    gotoxy(0, y);
    cout << x + 1;
    gotoxy(20, y);
    cout << Product_Names[x];
    gotoxy(47, y);
    cout << Selling_Prices[x];
    gotoxy(70, y);
    cout << Quantities[x];
    y++;
  }
  getch();
}

int load_for_shoping(string Product_Names[], float Quantities[], float Selling_Prices[])
{
  fstream f;
  string record;
  int idx = 0;
  f.open("Stock.txt", ios::in);
  while (!(f.eof()))
  {
    getline(f, record);
    if (record != "")
    {
      Product_Names[idx] = parseData(record, 1);
      Quantities[idx] = stof(parseData(record, 2));
      Selling_Prices[idx] = stof(parseData(record, 4));
      idx++;
    }
  }
  f.close();
  return idx;
}

void display_stock_header_for_Shoping() // function for just display
{
  system("CLS");
  SetConsoleTextAttribute(hConsole, 3); // Aqua
  gotoxy(30, 0);
  cout << "---------------------";
  gotoxy(30, 1);
  cout << " **** CUSTOMERS **** ";
  gotoxy(30, 2);
  cout << "---------------------";
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(30, 4);
  cout << "       SHOPING";

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(0, 6);
  cout << "Sr.No";
  gotoxy(20, 6);
  cout << "Product Name";
  gotoxy(47, 6);
  cout << "Selling Price";
  gotoxy(70, 6);
  cout << "Stock Left";

  SetConsoleTextAttribute(hConsole, 7); // White
}

void addtoCart(int arrayCount)
{
  int number;
  cout << endl;
  cout << arrayCount;
  SetConsoleTextAttribute(hConsole, 4); // Red
  cout << "How many things you want to buy: ";
  SetConsoleTextAttribute(hConsole, 7); // White
  cin >> number;
  int num, quantity;

  if (number > 0) //& number < arrayCount
  {
    for (int x = 0; x < number; x++)
    {
      cout << "Enter the Sr.No of the Product: ";
      cin >> num;
      cout << "Enter the Quantity: ";
      cin >> quantity;
    }
  }
  system("CLS");
}