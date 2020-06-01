
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

    int cmmdPromptDis = 10;
    int prgmDelay = 150;

    const int Height = 12;
    const int Width = 30;

    const char upperBound = (char)220u;
    const char lowerBound = (char)223u;

  int fruitX, fruitY;

  int initialX = ((Width -6)/2);
  int initialY = (Height /2);
  int X = initialX, changeInX;
  int Y = initialY;
  int tempX = (initialX*2);
  int UserInput, holdUserValue, verifyInput;

  char PlayerHead = '0';/// moved into class
  char PlayerBodySegment = 'O';
  char Fruit = (char)15u;
  char Matrix [Height][Width];
  char MatrixSlot = ' ';

       struct bodySegment
{
    int SegmentX, SegmentY;
    bodySegment* nextSegment;
};

class bodySegmentFunctions
{
    private:
        bodySegment* head;
        bodySegment* tail;

        char PlayerHead = '0';
        char PlayerBodySegment = 'O';

    public:
        bodySegmentFunctions()
        {
            head = NULL;
            tail = NULL;
        }

    void createSegment(int inputX, int inputY)
        {
            bodySegment* temp = new bodySegment;

            (*temp).SegmentX = inputX;
            (*temp).SegmentY = inputY;
            (*temp).nextSegment = NULL;

            if (head == NULL)
            {
                head = temp;
                tail = temp;
                temp = NULL;
            }
            else
            {
                (*tail).nextSegment = temp;

                tail = temp;
            }
        }

    int displayPlayer()
    {
        bodySegment* currentSegment = new bodySegment;

        currentSegment = head;

        while (currentSegment != NULL)
        {
            if (currentSegment == head)
            {
                Matrix [(*currentSegment).SegmentY][(*currentSegment).SegmentX] = PlayerHead;
            }
            else
            {
                Matrix [(*currentSegment).SegmentY][(*currentSegment).SegmentX] = PlayerBodySegment;
            }


            currentSegment = (*currentSegment).nextSegment;
        }
    }

    void addBodySegment(int inputX, int inputY)
    {
        bodySegment* temp = new bodySegment;

        (*temp).SegmentX = inputX;
        (*temp).SegmentY = inputY;

        (*temp).nextSegment = head;

        head = temp;
    }

    void removeBodySegment()
    {
        bodySegment* currentSegment = new bodySegment;
        bodySegment* previousSegment = new bodySegment;

        currentSegment = head;

        while ((*currentSegment).nextSegment != NULL)
        {
            previousSegment = currentSegment;

            currentSegment = (*currentSegment).nextSegment;
        }

        tail = previousSegment;

        (*previousSegment).nextSegment = NULL;

        delete currentSegment;
    }
};

        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void  Dis()
{
    for (int i = 0; i < cmmdPromptDis; i++)
    {
        printf (" ");
    }
}

void MatrixBound()
{SetConsoleTextAttribute (h, FOREGROUND_BLUE|FOREGROUND_RED);

    Dis();

for (int i = 0, i2 = 0, deleter = -3; i < 2; i++, i2++)
   {
          if (i2 > 0) {deleter = 3;}

            for (int i = 0; i < (Width + 3) - deleter; i++)
        {
            printf ( "%c", upperBound);
        }

       if (i2 > 0) {printf ("%c %c", upperBound, (char)219u );}

       printf ("\n");

       Dis();

       if (deleter == -3) {printf ("%c %c", (char)219u, upperBound);}
   }
}

void MatrixBound2()
{
     int i, i2, deleter;

    for ( i = 0, i2 = 0, deleter = 3; i < 2; i++, i2++)
    {
            if (i2 > 0) {deleter = -3;}

           if (deleter == 3) {printf ("%c %c", (char)219u, lowerBound);}

            for (int i = 0; i < (Width + 3) - deleter; i++)
            {
                printf ( "%c", lowerBound);
            }
               if (deleter == 3) {printf ("%c %c", lowerBound, (char)219u);}

        if (i2 < 0) {printf ("%c %c", lowerBound, (char)219u );}    printf ("\n");

        Dis();

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

void MatrixDisplaySetup()
{
    int iterator1X = 0, iterator2Y = 0;

for (int i = 0; i < Height; i++, iterator2Y++)
    {
          for (int i = 0; i < Width; i++, iterator1X++)
            {
            Matrix [iterator2Y][iterator1X] = MatrixSlot;
            }
        iterator1X = 0;
    }
        iterator2Y = 0;

        bodySegmentFunctions instance;//Instantiates the linked list/ snake body segments class called bodySegmentFunstions

        instance.createSegment(X, Y);// creates the head and stores it in the linked list.

        instance.displayPlayer();

    Matrix [fruitY] [fruitX] = Fruit;
}

void MatrixDisplay()
{
    MatrixBound();

       int iterator1X = 0, iterator2Y = 0;

    for (int i = 0; i < Height; i++, iterator2Y++)
        {
                printf ("%c %c", (char)219u, (char)219u);

            for (int i = 0; i < Width; i++, iterator1X++)
            {
                SetConsoleTextAttribute (h, FOREGROUND_INTENSITY|FOREGROUND_GREEN);
                if (Matrix [iterator2Y][iterator1X] == Fruit)
                {
                    SetConsoleTextAttribute (h, FOREGROUND_RED);
                }
                printf("%c",Matrix [iterator2Y][iterator1X] );

            }
             SetConsoleTextAttribute (h, FOREGROUND_BLUE|FOREGROUND_RED);

             printf ("%c %c", (char)219u, (char)219u);

             printf ("\n"); Dis(); iterator1X = 0;
        }
            iterator2Y = 0;

    MatrixBound2();

}

bool MatrixDisAllowOnce = true;

void MatrixDisplay2()
{
    int parameterX = cmmdPromptDis + X + 3, parameterY = Y + 4, tempPosX = X, tempPosY = Y;

    if (MatrixDisAllowOnce == true || (tempPosX != X && tempPosY != Y) )
    {
        printf("%c", PlayerHead); MatrixDisAllowOnce = false;
    }

}

void Setup()
{

    MatrixDisplaySetup();

    MatrixDisplay();

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
    if (X > (Width) || X < 0 || Y > Height || Y < 0)
    {
        GameOver = true;
        ProgramEsc = true;
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
        Game();

    if (X == fruitX && Y == fruitY)
    {
        FruitCoordsVerify = false;
        FruitPresent = false;
    }

     Sleep(prgmDelay);
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
