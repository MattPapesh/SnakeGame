
#include <iostream>

#include <chrono>

#include <windows.h>

#include <conio.h>

#include <ctime>


    bool GameOver = false;
    bool GameRestart = false;
    bool ProgramEsc = false;
    bool FruitPresent = false;
    bool FruitCoordsVerify = false;

    int Height = 10;//17
    int Width = 30;//50
    int cmmdPromptDis = 25;


  int fruitX, fruitY;

  int initialX = ((Width -6)/2);
  int initialY = (Height /2);
  int X = initialX ;
  int Y = initialY ;
  int tempX = (initialX*2);
  int UserInput, holdUserValue, verifyInput;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void  Dis()
{
    for (int i = 0; i < cmmdPromptDis; i++)
    {
        printf  (" ");
    }
}

void FruitCoords()
{

    while (!FruitCoordsVerify)
    {
        srand(time(NULL));

    if (!FruitPresent)
    {
        fruitX = (rand()%(Width-6));
        fruitY = (rand()%(Height-2));
        FruitPresent = true;
        FruitCoordsVerify = true;
    }
        if (fruitY < 2)
        {
         fruitY = fruitY + 2;
        }


    }


}


void hBound()
{

 SetConsoleTextAttribute(h,FOREGROUND_BLUE);

    for (int i=0; i < Width; i++)
    {
        printf ("_");
    }

    printf ("\n");
    Dis();
    for (int i=0; i < Width; i++)

    {
        printf ("_");
    }


}
void hBound2()
{
    printf ("| |");

 for (int i=6; i < (Width); i++)
    {
        printf ("_");
    }

printf ("| |");

    printf ("\n");

    Dis();

    printf ("| |");

    for (int i=6; i < Width; i++)

    {
        printf ("_");
    }

    printf ("| |\n");
}

void DisBounderies()
{

    Dis();
    hBound();
    printf ("\n");

int return1 = 0;

    for (int i=0; i < Height; i++)
    {return1++;
         Dis();

      if (return1 == fruitY)
      {
          printf ("| |");

          if (fruitY != Y)
          {

          for (int i = 0; i < (fruitX-1); i++)
          {
                printf (" ");
          }
                SetConsoleTextAttribute(h, FOREGROUND_RED|FOREGROUND_INTENSITY);

                printf ("O");

                SetConsoleTextAttribute(h, FOREGROUND_BLUE);

            for (int i = 0; i < (tempX - fruitX); i++)
            {
                printf (" ");
            }
      }
      else
      {
          if (X < fruitX)
          {
              for (int i = 0; i < (X - 1); i++)
              {
                  printf (" ");
              }

              SetConsoleTextAttribute(h, FOREGROUND_GREEN|FOREGROUND_INTENSITY);

              printf ("0");

              SetConsoleTextAttribute(h, FOREGROUND_BLUE);

              for (int i = 0; i < (fruitX - 1); i++)
              {
                  printf (" ");
              }

              SetConsoleTextAttribute(h, FOREGROUND_RED|FOREGROUND_INTENSITY);

              printf ("O");

              SetConsoleTextAttribute(h, FOREGROUND_BLUE);

              for (int i = 0; i < (tempX - fruitX); i++)
              {
                  printf (" ");
              }

          }
      }
    }

      else if (return1 == Y) /// This line is to find out the location of the player and print it upon the right line in the right position.
      { printf ("| |");
     for (int i = 0; i < (X-1); i++)
     {
         printf (" ");
     }

 SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY);

     printf ("O");

SetConsoleTextAttribute(h,FOREGROUND_BLUE);

     for (int i = 0; i < (tempX - X); i++)
     {
         printf (" ");
     }
}

else
{ printf ("| |");
     for (int i = 0; i < tempX; i++) {printf(" ");}

}

     for (int i; i < (X - Width); i++) {printf (" ");}

      printf ("| |\n");
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
std::cout << UserInput;
 printf ("\n");
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

void PlayerDeath()
{
    if (X >= )
    {

    }
}

void Logic()
{
ControlLogic();

 FruitCoords();

 PlayerDeath();

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

    if (X == fruitX && Y == fruitY)
    {
        FruitPresent = false;
    }

std::cout << "x: "<< fruitX<< std::endl<< "y: "<<fruitY<<std::endl;
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




