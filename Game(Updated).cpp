
#include <iostream>

#include <chrono>

#include <windows.h>

#include <conio.h>

using namespace std;

    bool GameOver = false;
    bool GameRestart = false;
    bool ProgramEsc = false;

    int Height = 34;
    int Width = 100;
    int cmmdPromptDis = 25;


  int fruitX, fruitY;

  int initialX = ((Width -6)/2);
  int initialY = (Height /2);
  int X = initialX ;
  int Y = (initialY );
  int UserInput, holdUserValue, verifyInput;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void  Dis()
{
    for (int i = 0; i < cmmdPromptDis; i++)
    {
        cout << " ";
    }
}

void hBound()
{

 SetConsoleTextAttribute(h,FOREGROUND_BLUE);

    for (int i=0; i < Width; i++)
    {
        cout << "_";
    }

    cout << endl;
    Dis();
    for (int i=0; i < Width; i++)

    {
        cout << "_";
    }


}
void hBound2()
{
    cout << "| |";

 for (int i=6; i < (Width); i++)
    {
        cout << "_";
    }

cout << "| |";

    cout << endl;

    Dis();

    cout << "| |";

    for (int i=6; i < Width; i++)

    {
        cout << "_";
    }

    cout << "| |"<< endl;
}

void DisBounderies()
{

    Dis();
    hBound();
    cout << endl;

int return1 = 0;
    for (int i=0; i < Height; i++)
    {return1++;
         Dis();



      if (return1 == Y) /// This line is to find out the location of the player and print it upon the right line in the right position.
{ cout << "| |";
     for (int i = 0; i < (X-1); i++)
     {
         cout << " ";
     }

 SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY);

     cout << "O";

SetConsoleTextAttribute(h,FOREGROUND_BLUE);
    int tempX = (initialX*2);
     for (int i = 0; i < (tempX - X); i++)
     {
         cout << " ";
     }
}

else
{
     cout <<"| |                                                                                              ";
}

     for (int i; i < (X - Width); i++) {cout << " ";}

      cout << "| |" << endl;
    }

    Dis();

    hBound2();

}

void Setup()
{
    DisBounderies();


}




void OtherControls()
{
    if (kbhit() == 1)
  {
      UserInput = getch();

  }

if (UserInput == 27) {GameOver = true; ProgramEsc = true;}

if (UserInput == 32) {getch();}

if (UserInput == 114) {GameOver = true; Sleep(500); GameRestart = true;}

}

void GameControls()
{
 if (UserInput == 119) {Y--; holdUserValue = 119; verifyInput++;}

if (UserInput == 115) {Y++; holdUserValue = 115; verifyInput++;}

if (UserInput == 97) {X--; holdUserValue = 97; verifyInput++;}

if (UserInput == 100) {X++; holdUserValue = 100; verifyInput++;}
cout << UserInput <<endl;
if(verifyInput > 0) {UserInput = holdUserValue;}
}

void KeyBoardFunctions()
{
 OtherControls();
 GameControls();
}

void ControlLogic()
{
 KeyBoardFunctions();


}

void Logic()
{
ControlLogic();




}
void Game()
{


}




main()
{

while (!ProgramEsc)
  {

  GameOver = false;

    while (!GameOver)
    {
Setup();
        Logic();



        Game();

system("cls");
        }

        if (GameRestart = true)
    {
        GameOver = true;
        X = initialX;
        Y = initialY;
        UserInput = 32;
        holdUserValue = 0;
        system("cls");
    }
    else
    {
        ProgramEsc = true;
    }

  }

}



















