#include <iostream>  // input output
#include <windows.h> // gotoxy
#include <fstream>   // File Handling
#include <ctime>     // Srand function
#include <conio.h>   // system ClS
using namespace std;

/**************************** Function Prototypes ****************************/

void gotoxy(int x, int y);

/************* Load and print maze from file *************/
void load(char maze[][61], int rowSize, int colSize, string path);
void printMaze(char maze[][61], int colSize, int rowSize);

/************* Movement *************/
void moveLeft(char maze[][61], int &xIdx, int &yIdx);
void moveRight(char maze[][61], int &xIdx, int &yIdx);
void moveUp(char maze[][61], int &xIdx, int &yIdx);
void moveDown(char maze[][61], int &xIdx, int &yIdx);
int random();

void gamePlay(bool gameRunning, char maze[][61], int &xIdx, int &yIdx);

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
  maze[xIdx][yIdx] = 'T';
  system("CLS");

  printMaze(maze, colSize, rowSize); // End of Load and Printing objects and maze

  gamePlay(1, maze, xIdx, yIdx);
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

void gamePlay(bool gameRunning, char maze[][61], int &xIdx, int &yIdx)
{
  time_t end = time(NULL) + 120;
  while (time(NULL) <= end && gameRunning == true)
  {
    Sleep(200);

    // if (random() == 0)
    // {
    //   // int policeX =
    //   cout << "Left" << endl;
    // }
    // if (random() == 1)
    // {
    //   cout << "Right" << endl;
    // }
    // if (random() == 2)
    // {
    //   cout << "Up" << endl;
    // }
    // if (random() == 3)
    // {
    //   cout << "Down" << endl;
    // }

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