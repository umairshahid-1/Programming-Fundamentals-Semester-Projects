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

void gamePlay(bool gameRunning, char maze[][61], int &xIdx, int &yIdx, int &police1X, int &police1Y, int &police2X, int &police2Y, int &police3X, int &police3Y);

/**************************** Main Function ****************************/
main()
{
  char maze[25][61]; // 2d array for maze
  string path = "maze.txt";

  int rowSize = sizeof(maze) / sizeof(maze[0]);
  int colSize = sizeof(maze[0]) / sizeof(maze[0][0]);

  load(maze, rowSize, colSize, path);

  int xIdx = 23; // Printing Player at specific position
  int yIdx = 30;
  maze[xIdx][yIdx] = 'T';

  int police1X = 1; // Printing Police at specific position
  int police1Y = 30;
  maze[police1X][police1Y] = 'P';

  int police2X = 12;
  int police2Y = 58; // Printing Police at specific position
  maze[police2X][police2Y] = 'P';

  int police3X = 12; // Printing Police at specific position
  int police3Y = 1;
  maze[police3X][police3Y] = 'P';

  system("CLS");

  printMaze(maze, colSize, rowSize); // End of Load and Printing objects and maze

  gamePlay(1, maze, xIdx, yIdx, police1X, police1Y, police2X, police2Y, police3X, police3Y);
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

void gamePlay(bool gameRunning, char maze[][61], int &xIdx, int &yIdx, int &police1X, int &police1Y, int &police2X, int &police2Y, int &police3X, int &police3Y)
{
  time_t end = time(NULL) + 120;
  while (time(NULL) <= end && gameRunning == true)
  {
    Sleep(200);

    int position = random();

    if (position == 0) // Left
    {
      if (maze[police2X][police2Y - 1] == ' ') // checking and Printing space
      {
        maze[police2X][police2Y] = ' ';
        gotoxy(police2Y, police2X);
        cout << " ";

        police2Y--;

        maze[police2X][police2Y] = 'P'; // Printing object
        gotoxy(police2Y, police2X);
        cout << 'P';
      }
    }

    if (position == 1) // Right
    {
      if (maze[police3X][police3Y + 1] == ' ') // checking and Printing space
      {
        maze[police3X][police3Y] = ' ';
        gotoxy(police3Y, police3X);
        cout << " ";

        police3Y++;

        maze[police3X][police3Y] = 'P'; // Printing object
        gotoxy(police3Y, police3X);
        cout << 'P';
      }
    }

    if (position == 2) // Up
    {
      if (maze[police1X - 1][police1Y] == ' ') // checking and Printing space
      {
        maze[police1X][police1Y] = ' ';
        gotoxy(police1Y, police1X);
        cout << " ";

        police1X--;

        maze[police1X][police1Y] = 'P'; // Printing object
        gotoxy(police1Y, police1X);
        cout << 'P';
      }
    }

    if (position == 3) // Down
    {
      if (maze[police1X + 1][police1Y] == ' ') // checking and Printing space
      {
        maze[police1X][police1Y] = ' ';
        gotoxy(police1Y, police1X);
        cout << " ";

        police1X++;

        maze[police1X][police1Y] = 'P'; // Printing object
        gotoxy(police1Y, police1X);
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