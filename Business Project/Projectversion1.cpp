#include <iostream>  //input,output
#include <conio.h>   //clearscreen
#include <stdlib.h>  //getch
#include <windows.h> //gotoxy
using namespace std;

// Proto Types
void clearscreen();
void gotoxy(int x, int y);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Colour Function
void Header();
char Entering();

// Functions for Admin
string Admin_Entering();
char Retype_Passwords();
int Admin_Menu();

// Function for Viewing Stock in Sorting Order
void View_Stock_Header();
char Sorting_Order();
int Smallest(float Array[], int Size, int Position);
int Largest(float Array[], int Size, int Position);
void Sorting1(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Size);
void Sorting2(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Size);

// Function for Adding New Employees
int Add_Employees_Header(string ID[], string Passwords[], int Employee_Count);
void Add_Employees_Record_In_Array(string ID[], string Passwords[], string Id, string Password, int Employee_Count);

// Function for Leaving message for Employees
void Leaving_Message();

// Functions for Employees
bool Employee_Entering(string ID[], string Passwords[], int Employee_Count);
bool Checking(string ID[], string Passwords[], string Id, string Password, int Employee_Count);
int Employee_Menu();

// Functions for Adding Stock
void Display_Stock_Header();
int Add_Stock_Header(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Product_count);
int Input_Data(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Product_count);
void Add_Stock_In_Array(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], string Name, float Quantity, float Purchase_Price, float Selling_Price, int Product_count);
void Array_Data(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Product_count);

// Functions for Updating Stock
void Update_Stock_Header();
void Update(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Option);
void Updating_Data(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Product_count);

// Function for Deleting Stock
void Delete_Stock_Header();
int Delete(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Product_count, int Option);
int Deleting_Data(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Product_count);

// Function for Customers
int Customer_SignUp(string Customers_Name[], string Customers_Password[], int Customer_Count);
void Add_Customers_Record_In_Array(string Customers_Name[], string Customers_Password[], string Name, string Password, int Customer_Count);

bool Customer_SignIn(string Customers_Name[], string Customers_Password[], int Customer_Count);
bool Customer_Checking(string Customers_Name[], string Customers_Password[], string Name, string Password, int Customer_Count);
int Customer_Menu();

main()
{
  // Local Arrays, Datastructures for Adding Stock
  const int Records = 20;
  int Product_count = 0;
  string Product_Names[Records];
  float Quantities[Records];
  float Purchase_Prices[Records];
  float Selling_Prices[Records];

  // Local Arrays, Datastructures for Adding Employees
  int Employee_Count = 0;
  string ID[Records];
  string Passwords[Records];

  // Local Arrays, Datastructures for Customers Sign Up
  int Customer_Count = 0;
  string Customers_Name[Records];
  string Customers_Password[Records];

  system("CLS");
  while (true) // Main While loop If the Entering Option is wrong than it will continue to run , Like in Admin Enetring option
  {
    char Main_Option = Entering(); // Checking that who is entering
    if (Main_Option == '1')        // At 1 there is Admin
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

                if (Option == '1') // Assending
                {
                  Sorting1(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                  Array_Data(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                }

                else if (Option == '2') // Decesending
                {
                  Sorting2(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                  Array_Data(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                }
                system("CLS");
              }

              else if (Option == 2) // Add New Employees
              {
                Employee_Count = Add_Employees_Header(ID, Passwords, Employee_Count);
              }

              else if (Option == 3) // Gross Income
              {
                cout << "Gross Income" << endl;
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
                Leaving_Message();
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
        bool check = true;
        check = Employee_Entering(ID, Passwords, Employee_Count);

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
                Product_count = Add_Stock_Header(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                if (Product_count > Records) // if Products which is added is greater than Records than this
                {
                  cout << "No more Space! " << endl;
                  system("CLS");
                }
              }

              else if (Option == 2) // Update Stock
              {
                Update_Stock_Header();
                Updating_Data(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
              }

              else if (Option == 3) // Delete Stock
              {
                Delete_Stock_Header();
                Product_count = Deleting_Data(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
              }

              else if (Option == 4) // View Stock
              {
                char Option = '0';
                Option = Sorting_Order(); // Ask in which do you want to see the sorting with quantity based

                system("CLS");
                View_Stock_Header();

                if (Option == '1') // Assending
                {
                  Sorting1(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                  Array_Data(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                }

                else if (Option == '2') // Decesending
                {
                  Sorting2(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                  Array_Data(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                }
                system("CLS");
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
        bool check = true;
        check = Customer_SignIn(Customers_Name, Customers_Password, Customer_Count);

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

              if (Option == 1) // View Stock
              {
                char Option = '0';
                Option = Sorting_Order(); // Ask in which do you want to see the sorting with quantity based

                system("CLS");
                View_Stock_Header();

                if (Option == '1') // Assending
                {
                  Sorting1(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                  Array_Data(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                }

                else if (Option == '2') // Decesending
                {
                  Sorting2(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                  Array_Data(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
                }
                system("CLS");
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
      Customer_Count = Customer_SignUp(Customers_Name, Customers_Password, Customer_Count);
    }

    else if (Main_Option == '5') // At 5 Exit
    {
      system("CLS");
      Header();
      cout << "\n";
      SetConsoleTextAttribute(hConsole, 7);
      cout << "Thanks for using this Applicatin! " << endl;
      break;
    } // Main Exit from Function

    else
    {
      system("CLS");
      Header();
      cout << "\n";
      SetConsoleTextAttribute(hConsole, 4); // Red
      cout << "You Enter a Wrong Number! " << endl;
      SetConsoleTextAttribute(hConsole, 7); // White
      clearscreen();
    } // Incase of wrong option in Main Options
  }   // End Main While
} // End Main

// Function Definations

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

void Header() // Header on Start
{
  SetConsoleTextAttribute(hConsole, 6); // yellow
  gotoxy(50, 0);
  cout << "-----------------------------------------------------------";
  gotoxy(50, 1);
  cout << "!              Simple Shop Management System              !";
  gotoxy(50, 2);
  cout << "-----------------------------------------------------------";

  gotoxy(50, 4);
  cout << "              ********************************";
  gotoxy(50, 5);
  cout << "              !           MAIN MENU          !";
  gotoxy(50, 6);
  cout << "              ********************************";
  cout << endl;
}

char Entering() // Who Is Entering
{
  Header();
  SetConsoleTextAttribute(hConsole, 2); // Green
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
  cout << "<3> Gross Income " << endl;
  cout << "<4> Transfer Salaries " << endl;
  cout << "<5> Pay Bills " << endl;
  cout << "<6> Total Profit " << endl;
  cout << "<7> History of Sales " << endl;
  cout << "<8> Offer Discount " << endl;
  cout << "<9> Leave Message" << endl;
  cout << "<0> Return to Starting Menu" << endl;

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

int Smallest(float Array[], int Size, int Position) // find the Index where there is smallest Number in the Array for Asending order sorting
{
  int index = Position;
  int temp = Array[Position];

  for (int x = Position; x < Size; x++)
  {
    if (temp > Array[x])
    {
      temp = Array[x];
      index = x;
    }
  }

  return index;
}

int Largest(float Array[], int Size, int Position) // find the Index where there is Largest Number in the Array for Descending order sorting
{
  int index = Position;
  int temp = Array[Position];

  for (int x = Position; x < Size; x++)
  {
    if (temp < Array[x])
    {
      temp = Array[x];
      index = x;
    }
  }

  return index;
}

void Sorting1(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Size)
{
  for (int x = 0; x < Size; x++)
  {
    int Ind = Smallest(Quantities, Size, x);

    int temp = Quantities[x];
    Quantities[x] = Quantities[Ind];
    Quantities[Ind] = temp;

    string temp1 = Product_Names[x];
    Product_Names[x] = Product_Names[Ind];
    Product_Names[Ind] = temp1;

    int temp2 = Purchase_Prices[x];
    Purchase_Prices[x] = Purchase_Prices[Ind];
    Purchase_Prices[Ind] = temp2;

    int temp3 = Selling_Prices[x];
    Selling_Prices[x] = Selling_Prices[Ind];
    Selling_Prices[Ind] = temp3;
  }
}

void Sorting2(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Size)
{
  for (int x = 0; x < Size; x++)
  {
    int Ind = Largest(Quantities, Size, x);

    int temp = Quantities[x];
    Quantities[x] = Quantities[Ind];
    Quantities[Ind] = temp;

    string temp1 = Product_Names[x];
    Product_Names[x] = Product_Names[Ind];
    Product_Names[Ind] = temp1;

    int temp2 = Purchase_Prices[x];
    Purchase_Prices[x] = Purchase_Prices[Ind];
    Purchase_Prices[Ind] = temp2;

    int temp3 = Selling_Prices[x];
    Selling_Prices[x] = Selling_Prices[Ind];
    Selling_Prices[Ind] = temp3;
  }
}

int Add_Employees_Header(string ID[], string Passwords[], int Employee_Count) // Functon for Adding Employees
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

  string Id, Password;

  SetConsoleTextAttribute(hConsole, 6);
  gotoxy(0, 7);
  cout << "Enter the ID of the Employee: ";
  gotoxy(0, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin.ignore();
  getline(cin, Id);

  gotoxy(45, 7);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Assign Password: ";
  gotoxy(45, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin >> Password;

  Add_Employees_Record_In_Array(ID, Passwords, Id, Password, Employee_Count);
  Employee_Count++;

  system("CLS");
  return Employee_Count;
}

void Add_Employees_Record_In_Array(string ID[], string Passwords[], string Id, string Password, int Employee_Count)
{
  ID[Employee_Count] = Id;
  Passwords[Employee_Count] = Password; // Function For Adding Employees Data from variable to Array
}

void Leaving_Message() // Function Header for Leaving Message
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
}

bool Employee_Entering(string ID[], string Passwords[], int Employee_Count) // Employee entering Assigned Id and Password
{
  SetConsoleTextAttribute(hConsole, 4); // Red
  gotoxy(30, 0);
  cout << "-------------------";
  gotoxy(30, 1);
  cout << "**** Employees ****";
  gotoxy(30, 2);
  cout << "-------------------";

  string Id, Password;

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(0, 4);
  cout << "Enter Your Id: ";
  SetConsoleTextAttribute(hConsole, 7); // white
  gotoxy(0, 6);
  cin.ignore();
  getline(cin, Id);

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(30, 4);
  cout << "Enter Your Password: ";
  SetConsoleTextAttribute(hConsole, 7); // white
  gotoxy(30, 6);
  getline(cin, Password);

  bool flag = true;
  flag = Checking(ID, Passwords, Id, Password, Employee_Count);
  return flag;
}

bool Checking(string ID[], string Passwords[], string Id, string Password, int Employee_Count)
{
  for (int x = 0; x < Employee_Count; x++)
  {
    if (ID[x] == Id && Passwords[x] == Password)
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
  cout << "<0> Return to Main Menu" << endl;

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

int Add_Stock_Header(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Product_count)
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

  int Count = Input_Data(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count);
  system("CLS");

  return Count;
}

int Input_Data(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Product_count) // Function for taking Input
{
  string Name;
  float Quantity, Purchase_Price, Selling_Price;

  SetConsoleTextAttribute(hConsole, 6);
  gotoxy(0, 7);
  cout << "Name of Products";
  gotoxy(0, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin.ignore();
  getline(cin, Name);

  gotoxy(31, 7);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Quantity of Products";
  gotoxy(31, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin >> Quantity;

  gotoxy(66, 7);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Purchasing price";
  gotoxy(66, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin >> Purchase_Price;

  gotoxy(97, 7);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Selling Price";
  gotoxy(97, 9);
  SetConsoleTextAttribute(hConsole, 7);
  cin >> Selling_Price;

  Add_Stock_In_Array(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Name, Quantity, Purchase_Price, Selling_Price, Product_count);
  Product_count++;

  return Product_count;
}

void Add_Stock_In_Array(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], string Name, float Quantity, float Purchase_Price, float Selling_Price, int Product_count)
{
  Product_Names[Product_count] = Name;
  Quantities[Product_count] = Quantity; // Function For Adding Stock from variable to Array
  Purchase_Prices[Product_count] = Purchase_Price;
  Selling_Prices[Product_count] = Selling_Price;
}

void Array_Data(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Product_count) // Displaying the Data of the Array
{
  int y = 9;
  for (int x = 0; x < Product_count; x++)
  {
    gotoxy(0, y);
    cout << x + 1;
    gotoxy(20, y);
    cout << Product_Names[x];
    gotoxy(47, y);
    cout << Quantities[x];
    gotoxy(70, y);
    cout << Purchase_Prices[x];
    gotoxy(101, y);
    cout << Selling_Prices[x];
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

void Update(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Option) // Function for Update the Stock
{
  string Name;
  float Quantity, Purchase_Price, Selling_Price;

  cout << endl;
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Name of the Product : ";
  SetConsoleTextAttribute(hConsole, 7);
  cin.ignore();
  getline(cin, Name);

  SetConsoleTextAttribute(hConsole, 6);
  cout << "Quantity of Product : ";
  SetConsoleTextAttribute(hConsole, 7);
  cin >> Quantity;

  SetConsoleTextAttribute(hConsole, 6);
  cout << "Purchasing price : ";
  SetConsoleTextAttribute(hConsole, 7);
  cin >> Purchase_Price;

  SetConsoleTextAttribute(hConsole, 6);
  cout << "Selling Price : ";
  SetConsoleTextAttribute(hConsole, 7);
  cin >> Selling_Price;

  Product_Names[Option - 1] = Name;
  Quantities[Option - 1] = Quantity;
  Purchase_Prices[Option - 1] = Purchase_Price;
  Selling_Prices[Option - 1] = Selling_Price;
}

void Updating_Data(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Product_count) // Array before updating , Displaying the Array
{
  int y = 9;
  for (int x = 0; x < Product_count; x++)
  {
    gotoxy(0, y);
    cout << x + 1;
    gotoxy(20, y);
    cout << Product_Names[x];
    gotoxy(47, y);
    cout << Quantities[x];
    gotoxy(70, y);
    cout << Purchase_Prices[x];
    gotoxy(101, y);
    cout << Selling_Prices[x];
    y++;
  }

  int Option = 1;
  gotoxy(0, y + 1);
  SetConsoleTextAttribute(hConsole, 4); // Red
  cout << "Enter your Option: ";
  SetConsoleTextAttribute(hConsole, 7); // White
  cin >> Option;

  if (Option > 0)
  {
    Update(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Option);

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

int Delete(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Product_count, int Option) // Actual Function for Deleting the Data from the Array
{
  if (Product_count > 0)
  {
    for (int x = Option - 1; x < Product_count - 1; x++)
    {
      Product_Names[x] = Product_Names[x + 1];
      Quantities[x] = Quantities[x + 1];
      Purchase_Prices[x] = Purchase_Prices[x + 1];
      Selling_Prices[x] = Selling_Prices[x + 1];
    }

    Product_count--; // Because after Deletition , Size of the Array will be decrease
  }
  return Product_count;
}

int Deleting_Data(string Product_Names[], float Quantities[], float Purchase_Prices[], float Selling_Prices[], int Product_count) // Array before Deleting , Displaying the Array
{
  int y = 9;
  for (int x = 0; x < Product_count; x++)
  {
    gotoxy(0, y);
    cout << x + 1;
    gotoxy(20, y);
    cout << Product_Names[x];
    gotoxy(47, y);
    cout << Quantities[x];
    gotoxy(70, y);
    cout << Purchase_Prices[x];
    gotoxy(101, y);
    cout << Selling_Prices[x];
    y++;
  }

  int Option;
  gotoxy(0, y + 1);
  SetConsoleTextAttribute(hConsole, 4); // Red
  cout << "Enter your Option: ";
  SetConsoleTextAttribute(hConsole, 7); // White
  cin >> Option;

  if (Option > 0)
  {
    Product_count = Delete(Product_Names, Quantities, Purchase_Prices, Selling_Prices, Product_count, Option);

    gotoxy(40, y + 3);
    SetConsoleTextAttribute(hConsole, 4); // Red
    cout << "Dleted Successfuly!";

    getch();
  }

  system("CLS");

  return Product_count;
}

int Customer_SignUp(string Customers_Name[], string Customers_Password[], int Customer_Count) // Function for Customers Signup
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

  string Name, Password, Retype_Password;

  SetConsoleTextAttribute(hConsole, 6);
  gotoxy(0, 7);
  cout << "Enter Your Name:";
  gotoxy(16, 8);
  SetConsoleTextAttribute(hConsole, 7);
  cin.ignore();
  getline(cin, Name);

  gotoxy(0, 10);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Enter the Password:";
  gotoxy(19, 11);
  SetConsoleTextAttribute(hConsole, 7);
  cin >> Password;

  gotoxy(0, 13);
  SetConsoleTextAttribute(hConsole, 6);
  cout << "Retype the Password:";
  gotoxy(20, 14);
  SetConsoleTextAttribute(hConsole, 7);
  cin >> Retype_Password;

  if (Password == Retype_Password)
  {
    Add_Customers_Record_In_Array(Customers_Name, Customers_Password, Name, Password, Customer_Count);
    Customer_Count++;

    gotoxy(40, 16);
    SetConsoleTextAttribute(hConsole, 4); // Red
    cout << "SignUp Successfully!";
    getch();
  }
  // else // incase if retype Password is incorrect then do this
  // {
  // }
  system("CLS");
  return Customer_Count;
}

void Add_Customers_Record_In_Array(string Customers_Name[], string Customers_Password[], string Name, string Password, int Customer_Count)
{
  Customers_Name[Customer_Count] = Name;
  Customers_Password[Customer_Count] = Password; // Function For Adding Employees Data from variable to Array
}

bool Customer_SignIn(string Customers_Name[], string Customers_Password[], int Customer_Count) // for customers SignIn
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

  string Name, Password;

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(0, 6);
  cout << "Enter Your Name: ";
  SetConsoleTextAttribute(hConsole, 7); // white
  gotoxy(0, 8);
  cin.ignore();
  getline(cin, Name);

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(30, 6);
  cout << "Enter Your Password: ";
  SetConsoleTextAttribute(hConsole, 7); // white
  gotoxy(30, 8);
  getline(cin, Password);

  bool flag = true;
  flag = Checking(Customers_Name, Customers_Password, Name, Password, Customer_Count);
  return flag;
}

bool Customer_Checking(string Customers_Name[], string Customers_Password[], string Name, string Password, int Customer_Count)
{
  for (int x = 0; x < Customer_Count; x++)
  {
    if (Customers_Name[x] == Name && Customers_Password[x] == Password)
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
  cout << "<1> View Stock " << endl;
  cout << "<2> View Discounted Products " << endl;
  cout << "<0> Return to Main Menu" << endl;

  SetConsoleTextAttribute(hConsole, 6); // Yellow
  gotoxy(0, 9);
  cout << "Your Option: ";

  int Opt;
  SetConsoleTextAttribute(hConsole, 7); // White
  cin >> Opt;

  return Opt;
}