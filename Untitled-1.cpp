#include <iostream>  // input output
#include <windows.h> // gotoxy
#include <fstream>   // File Handling
#include <ctime>     // Srand function
#include <conio.h>   // system ClS
using namespace std;

/**************************** Function Prototypes ****************************/

void gotoxy(int x, int y);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Colour Function

/************* Load and print maze from file *************/
void load(char maze[][61], int rowSize, int colSize, string path);
void printMaze(char maze[][61], int colSize, int rowSize);

/************* Movement *************/
void moveLeft(char maze[][61], int &xIdx, int &yIdx);
void moveRight(char maze[][61], int &xIdx, int &yIdx);
void moveUp(char maze[][61], int &xIdx, int &yIdx);
void moveDown(char maze[][61], int &xIdx, int &yIdx);
int random();
void gamePlay(bool gameRunning, char maze[][61], int &xIdx, int &yIdx, int &policeX, int &policeY);
void timeDisplay(int seconds);

/**************************** Main Function ****************************/
main()
{
  char maze[25][61]; // 2d array for maze
  string path = "maze.txt";

  int rowSize = sizeof(maze) / sizeof(maze[0]);
  int colSize = sizeof(maze[0]) / sizeof(maze[0][0]);

  load(maze, rowSize, colSize, path);

  int xIdx = 12; // Printing Player at specific position
  int yIdx = 12;

  int policeX = 1; // Printing Police at specific position
  int policeY = 1;

  maze[xIdx][yIdx] = 'T';
  maze[policeX][policeY] = 'P';

  system("CLS");
  printMaze(maze, colSize, rowSize);

  SetConsoleTextAttribute(hConsole, 7); // White
  bool gameRunning = true;
  gamePlay(gameRunning, maze, xIdx, yIdx, policeX, policeY);
}

// Functions Definations
void gotoxy(int x, int y)
{
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

/************* Load and print maze from file *************/
void load(char maze[][61], int rowSize, int colSize, string path)
{
  fstream myFile;
  string record;
  myFile.open(path, ios::in);
  for (int row = 0; row < rowSize; row++)
  {
    getline(myFile, record);
    for (int col = 0; col < colSize; col++)
    {
      maze[row][col] = record[col];
    }
  }
}

void printMaze(char maze[][61], int colSize, int rowSize)
{
  for (int x = 0; x < rowSize; x++)
  {
    for (int y = 0; y < colSize; y++)
    {
      SetConsoleTextAttribute(hConsole, 2); // Green
      cout << maze[x][y];
    }
    cout << endl;
  }
}

/************* Movement *************/
void moveLeft(char maze[][61], int &xIdx, int &yIdx)
{
  if (maze[xIdx][yIdx - 1] == ' ') // checking and Printing space
  {
    maze[xIdx][yIdx] = ' ';
    gotoxy(yIdx, xIdx);
    cout << " ";

    yIdx--;

    maze[xIdx][yIdx] = 'T'; // Printing object
    gotoxy(yIdx, xIdx);
    cout << 'T';
  }
}

void moveRight(char maze[][61], int &xIdx, int &yIdx)
{
  if (maze[xIdx][yIdx + 1] == ' ') // checking and Printing space
  {
    maze[xIdx][yIdx] = ' ';
    gotoxy(yIdx, xIdx);
    cout << " ";

    yIdx++;

    maze[xIdx][yIdx] = 'T'; // Printing object
    gotoxy(yIdx, xIdx);
    cout << 'T';
  }
}

void moveUp(char maze[][61], int &xIdx, int &yIdx)
{
  if (maze[xIdx - 1][yIdx] == ' ') // checking and Printing space
  {
    maze[xIdx][yIdx] = ' ';
    gotoxy(yIdx, xIdx);
    cout << " ";

    xIdx--;

    maze[xIdx][yIdx] = 'T'; // Printing object
    gotoxy(yIdx, xIdx);
    cout << 'T';
  }
}

void moveDown(char maze[][61], int &xIdx, int &yIdx)
{
  if (maze[xIdx + 1][yIdx] == ' ') // checking and Printing space
  {
    maze[xIdx][yIdx] = ' ';
    gotoxy(yIdx, xIdx);
    cout << " ";

    xIdx++;

    maze[xIdx][yIdx] = 'T'; // Printing object
    gotoxy(yIdx, xIdx);
    cout << 'T';
  }
}

int random()
{
  srand(time(0));
  int result = rand() % 4;
  return result;
}

void gamePlay(bool gameRunning, char maze[][61], int &xIdx, int &yIdx, int &policeX, int &policeY)
{
  time_t end = time(NULL) + 120;
  while (time(NULL) <= end && gameRunning == true)
  {
    Sleep(200);
    int seconds = 120;
    timeDisplay(seconds);
    seconds--;

    int position = random();

    if (position == 0) // Left
    {

      if (maze[policeX][policeY - 1] == ' ') // checking and Printing space
      {
        maze[policeX][policeY] = ' ';
        gotoxy(policeY, policeX);
        cout << " ";

        policeY--;

        maze[policeX][policeY] = 'P'; // Printing object
        gotoxy(policeY, policeX);
        cout << 'P';
      }
    }

    if (position == 1) // Right
    {

      if (maze[policeX][policeY + 1] == ' ') // checking and Printing space
      {
        maze[policeX][policeY] = ' ';
        gotoxy(policeY, policeX);
        cout << " ";

        policeY++;

        maze[policeX][policeY] = 'P'; // Printing object
        gotoxy(policeY, policeX);
        cout << 'P';
      }
    }

    if (position == 2) // UP
    {

      if (maze[policeX - 1][policeY] == ' ') // checking and Printing space
      {
        maze[policeX][policeY] = ' ';
        gotoxy(policeY, policeX);
        cout << " ";

        policeX--;

        maze[policeX][policeY] = 'P'; // Printing object
        gotoxy(policeY, policeX);
        cout << 'P';
      }
    }

    if (position == 3) // Down
    {

      if (maze[policeX + 1][policeY] == ' ') // checking and Printing space
      {
        maze[policeX][policeY] = ' ';
        gotoxy(policeY, policeX);
        cout << " ";

        policeX++;

        maze[policeX][policeY] = 'P'; // Printing object
        gotoxy(policeY, policeX);
        cout << 'P';
      }
    }

    if (GetAsyncKeyState(VK_LEFT))
    {
      moveLeft(maze, xIdx, yIdx);
    }

    if (GetAsyncKeyState(VK_RIGHT))
    {
      moveRight(maze, xIdx, yIdx);
    }

    if (GetAsyncKeyState(VK_UP))
    {
      moveUp(maze, xIdx, yIdx);
    }

    if (GetAsyncKeyState(VK_DOWN))
    {
      moveDown(maze, xIdx, yIdx);
    }

    if (GetAsyncKeyState(VK_ESCAPE))
    {
      gameRunning = false; // Stop the game
    }
  }
}

void timeDisplay(int seconds)
{
  int minutes = seconds / 60;
  int sec = seconds % 60;
  gotoxy(27, 50);
  cout << minutes << " : " << sec << endl;
}