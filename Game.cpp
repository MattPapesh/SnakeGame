
#include <iostream>

#include <chrono>

#include <windows.h>

#include <conio.h>

using namespace std;

    bool GameOver = false;

    int Height = 34;
    int Width = 100;
    int cmmdPromptDis = 25;
    int SleepSpeed = .1;

  int fruitX, fruitY;

  int initialX = ((Width -6)/2);
  int initialY = (Height /2);
  int X = initialX ;
  int Y = (initialY );
  int UserInput, UserInput2;


void  Dis()
{
    for (int i = 0; i < cmmdPromptDis; i++)
    {
        cout << " ";
    }
}

void hBound()
{

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
     cout << "O";
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


void Logic()
{





}

void ControlLogic()
{

}

void Game()
{


}




main()
{
    while (!GameOver)
    {

        Setup();

        Logic();

        Game();


    UserInput = getch();


if (UserInput == 119) {Y--; Sleep(SleepSpeed);}
if (UserInput == 115) {Y++; Sleep(SleepSpeed);}
if (UserInput == 97) {X--; Sleep(SleepSpeed);}
if (UserInput == 100) {X++; Sleep(SleepSpeed);}
cout << UserInput <<endl;
system("cls");
}
}
//My problem is that getch() gets the key that is being pressed at any given time to then determine the movement
//of the player and then the screen refreshes. But getch() waits for an input of any kind. The keys w a s and d will
//change the position of the player, others won't but still count. Sense the computer waits for a input the loop doesn't
// continue and in a game like snake the snake constantly moves until direction changes. This cannot occur because
// the computer waits for input each time the player moves one unit. If you added while loops into the if statements then
//the player will continously move but then will not have a way out of the loop so then the player can't do anything else.
//If you added a if statement to getch() then how would you access it only when necessary?
//Let me know what you think because I'm interested as to what you think might be a good approach.


















