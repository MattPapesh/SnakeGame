
// **THINGS WILL EVENTUALLY BE DEREFERENCED APPROPRIATELY**

#include <iostream>

#include <chrono>

#include <windows.h>

#include <conio.h>

#include <ctime>

    bool GameStart = false;
    bool GameOver = false;
    bool GameRestart = false;
    bool ProgramEsc = false;
    bool FruitPresent = false;
    bool FruitCoordsVerify = false;

    int cmmdPromptDis = 20;
    int cmmdPromptDisH = 2;
    int prgmDelay = 100;

    const int Height = 15;
    const int Width = 30;

    const char upperBound = (char)220u;
    const char lowerBound = (char)223u;

  int fruitX, fruitY;

  int initialX = ((Width -6)/2);
  int initialY = (Height /2);
  int X = initialX, changeInX;
  int Y = initialY;
  int bodySegmentsAfterHead = 0;

  int tempX = (initialX*2);
  int UserInput, holdUserValue, verifyInput;

  char PlayerHead = 'O';
  char Fruit = (char)15u;
  char Matrix [Height][Width];
  char MatrixSlot = ' ';

  bool once = false;

void CursurPos(int x, int y)
{
    COORD instance;

    instance.X = x;
    instance.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),instance);
}

void  Dis()
{
    for (int i = 0; i < cmmdPromptDis; i++)
    {
        printf (" ");
    }
}

void DisH()
{
    for (int i; i < cmmdPromptDisH; i++)
    {
        printf ("\n");
    }
}


    struct bodySegment
{
    int SegmentX, SegmentY;
    bodySegment* nextSegment;
};

class bodySegmentFunctions
{
    public:

        bool AddSeg = true;

        bodySegment* head;
        bodySegment* tail;

        char PlayerHead = (char)219u;
        char PlayerBodySegment = (char)219u;

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
        currentSegment = new bodySegment;

        delete currentSegment;

        return 0;
    }

        void snakeGrowth(int bodySegments)
        {
            if (AddSeg)
            {
                 for (int i = 0; i <= bodySegments; i++)
                {
                    createSegment(-1, 0);
                }

                AddSeg = false;
            }
            updateSegmentCoords(bodySegments);
        }

        void updateSegmentCoords(int bodySegments)
        {

            bodySegment* currentSegment = new bodySegment;
            bodySegment* previousSegment = new bodySegment;
            bodySegment* nextSaved = new bodySegment;
            bodySegment* previousSaved = new bodySegment;

            currentSegment = head;

            (*previousSaved).SegmentX = (*currentSegment).SegmentX;
            (*previousSaved).SegmentY = (*currentSegment).SegmentY;

            (*nextSaved).SegmentX = ( *(*currentSegment).nextSegment).SegmentX;
            (*nextSaved).SegmentY = ( *(*currentSegment).nextSegment).SegmentY;


             for (int i = 0; i != bodySegments; i++)
            {
              previousSegment = currentSegment;
              currentSegment = (*currentSegment).nextSegment;

              (*currentSegment).SegmentX = (*previousSaved).SegmentX;
              (*currentSegment).SegmentY = (*previousSaved).SegmentY;

            (*previousSaved).SegmentX = (*nextSaved).SegmentX;
            (*previousSaved).SegmentY = (*nextSaved).SegmentY;

            (*nextSaved).SegmentX = ( *(*currentSegment).nextSegment).SegmentX;
            (*nextSaved).SegmentY = ( *(*currentSegment).nextSegment).SegmentY;

            }

            delete previousSaved, nextSaved, currentSegment, previousSegment;
    }

    void touchingSegments()
    {

if (bodySegmentsAfterHead != 0)
{
     bodySegment* temp = new bodySegment;

        temp = (*head).nextSegment;

        while ( (*temp).nextSegment != NULL)
        {
            temp = (*temp).nextSegment;

            if( (*temp).SegmentX == (*head).SegmentX && (*temp).SegmentY == (*head).SegmentY )
            {
                GameOver = true;
                ProgramEsc = true;
            }
        }

        temp = new bodySegment;

        delete temp;
}

    }

};

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

class Menu
{
     char P = (char)219u, A = ' ';

int y, titleDis = 14;

public:

char titleMatrix [9][60]
{
    {P,P,P,P,P,P,P,P,A,A,P,P,A,A,A,A,A,A,A,A,P,P,A,A,A,A,A,A,A,A,P,P,A,A,A,A,A,A,A,A,P,P,A,A,A,A,A,A,P,P,A,A,P,P,P,P,P,P,P,P},
    {P,P,P,P,P,P,P,P,A,A,P,P,P,P,A,A,A,A,A,A,P,P,A,A,A,A,A,A,P,P,P,P,P,P,A,A,A,A,A,A,P,P,A,A,A,A,A,A,P,P,A,A,P,P,P,P,P,P,P,P},
    {P,P,A,A,A,A,A,A,A,A,P,P,P,P,P,P,A,A,A,A,P,P,A,A,A,A,P,P,P,P,A,A,P,P,P,P,A,A,A,A,P,P,A,A,A,A,P,P,P,P,A,A,P,P,A,A,A,A,A,A},
    {P,P,A,A,A,A,A,A,A,A,P,P,A,A,P,P,A,A,A,A,P,P,A,A,A,A,P,P,P,P,A,A,P,P,P,P,A,A,A,A,P,P,P,P,P,P,P,P,A,A,A,A,P,P,A,A,A,A,A,A},
    {P,P,P,P,P,P,P,P,A,A,P,P,A,A,P,P,P,P,A,A,P,P,A,A,A,A,P,P,A,A,A,A,A,A,P,P,A,A,A,A,P,P,P,P,P,P,A,A,A,A,A,A,P,P,P,P,A,A,A,A},
    {A,A,A,A,A,A,P,P,A,A,P,P,A,A,A,A,P,P,A,A,P,P,A,A,P,P,P,P,P,P,P,P,P,P,P,P,P,P,A,A,P,P,A,A,P,P,P,P,A,A,A,A,P,P,A,A,A,A,A,A},
    {A,A,A,A,A,A,P,P,A,A,P,P,A,A,A,A,P,P,P,P,P,P,A,A,P,P,P,P,P,P,P,P,P,P,P,P,P,P,A,A,P,P,A,A,A,A,P,P,P,P,A,A,P,P,A,A,A,A,A,A},
    {P,P,P,P,P,P,P,P,A,A,P,P,A,A,A,A,A,A,P,P,P,P,A,A,P,P,A,A,A,A,A,A,A,A,A,A,P,P,A,A,P,P,A,A,A,A,A,A,P,P,A,A,P,P,P,P,P,P,P,P},
    {P,P,P,P,P,P,P,P,A,A,P,P,A,A,A,A,A,A,A,A,P,P,A,A,P,P,A,A,A,A,A,A,A,A,A,A,P,P,A,A,P,P,A,A,A,A,A,A,P,P,A,A,P,P,P,P,P,P,P,P}
};

    void titleColor1()
    {
        SetConsoleTextAttribute (h, FOREGROUND_BLUE);

        if (y > 0 && y < 4) {SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); }

        if (y > 6 && y < 9) {SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); }
    }

    void titleColor2()
    {
        SetConsoleTextAttribute (h, FOREGROUND_BLUE);

        if (y > 1 && y < 5) {SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); }

        if (y > 7) {SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); }
    }

    void titleColor3()
    {
        SetConsoleTextAttribute (h, FOREGROUND_BLUE);

        if ( y > 2 && y < 5) {SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); }
    }

    void titleColor4()
    {
        SetConsoleTextAttribute (h, FOREGROUND_BLUE);

        if (y < 1) {SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); }

        if (y > 3 && y < 7) {SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); }
    }

    void titleColor5()
    {
        SetConsoleTextAttribute (h, FOREGROUND_BLUE);

        if (y < 2) {SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); }

        if (y > 4) {SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); }
    }

    void titleColor6()
    {
        SetConsoleTextAttribute(h, FOREGROUND_BLUE);

        if (y < 3) {SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); }

        if (y > 5) {SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); }
    }

int i, x;

    void displayTitle()
    {
    int temp = cmmdPromptDis;

    cmmdPromptDis = titleDis;

        for (NULL; i < 6; i++)
        {
            CursurPos(titleDis, 2);

            for (NULL; y < 9; y++)
            {
                if (i == 0) {titleColor1(); } else if (i == 1) {titleColor2(); } else if (i == 2) {titleColor3(); }

                else if (i == 3) {titleColor4(); } else if (i == 4) {titleColor5(); } else if (i == 5) {titleColor6(); }

                for (NULL; x < 60; x++)
                {
                    printf ("%c", titleMatrix [y][x]);
                }

                x = 0;

            CursurPos(titleDis, 2 + y);

            }
            y = 0, x = 0;

            Sleep(100);

            CursurPos(0,0);
        }
i = 0; x = 0;

cmmdPromptDis = temp;

    }

    bool start, once = true, once2 = true;

    void menuControl()
    {


        SetConsoleTextAttribute (h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

        CursurPos(3, 12);

        for (int i; i < 100; i++)
        {
            printf ("~");
        }

        if (kbhit() == 1)
        {
            UserInput = getch();
        }

        if (once)
        {
            UserInput = 119;

            once = false;
        }

        SetConsoleTextAttribute (h, FOREGROUND_RED | FOREGROUND_GREEN);

        if (UserInput == 119)
        {
            CursurPos(40, 14);

            start = true;

            SetConsoleTextAttribute (h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

            printf ("%c", (char)175u);

            SetConsoleTextAttribute (h, FOREGROUND_GREEN | FOREGROUND_RED);

            printf ("   START \n");
        }
        else if (UserInput == 115)
        {
            CursurPos(40, 14);

            printf ("   START \n");
        }

        if (once2)
        {
            UserInput = 115;

            once2 = false;
        }

        if (UserInput == 115)
        {
            CursurPos(40, 16);

            start = false;

            SetConsoleTextAttribute (h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

            printf ("%c", (char)175u);

            SetConsoleTextAttribute (h, FOREGROUND_GREEN | FOREGROUND_RED);

            printf ("   QUIT \n");
        }
        else if (UserInput == 119)
        {
            CursurPos(40, 16);

            printf ("   QUIT \n");
        }

        if (start && UserInput == 13)
        {
            GameStart = true;

            system ("cls");
        }
        else if (!start && UserInput == 13)
        {
            GameStart = true;

            ProgramEsc = true;

            GameOver = true;

            system ("cls");
        }
    }
};
    bodySegmentFunctions bSFinstance;

void MatrixBound()
{
    SetConsoleTextAttribute (h, FOREGROUND_BLUE|FOREGROUND_RED);

    CursurPos(0, cmmdPromptDisH); Dis();

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

        bool pass = true;

        bodySegment* temp = new bodySegment;

        temp = bSFinstance.head;

        while (temp != NULL)
        {
            if ( (*temp).SegmentX == fruitX && (*temp).SegmentY == fruitY)
            {
               pass = false;
            }

            temp = (*temp).nextSegment;
        }

        if (pass = true)
        {
            FruitPresent = true;
            FruitCoordsVerify = true;
        }
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

    if (!once)
    {
        bSFinstance.createSegment(X, Y);
    }

    (* (bSFinstance.head) ).SegmentX = X; ( (*bSFinstance.head) ).SegmentY = Y;

        Matrix [fruitY][fruitX] = Fruit;

        if ( Matrix [fruitY][fruitX] == Matrix [( *(bSFinstance.head) ).SegmentY] [( *(bSFinstance.head) ).SegmentX])
        {
            Matrix [fruitY] [fruitX] = PlayerHead;

            bodySegmentsAfterHead++;

            bSFinstance.AddSeg = true;
        }

        bSFinstance.displayPlayer();
}

void MatrixDisplay()
{
    MatrixBound();

       int iterator1X = 0, iterator2Y = 0;

    for (int i; i < Height; i++, iterator2Y++)
        {
                printf ("%c %c", (char)219u, (char)219u);

          /*  for (int i; i < Width; i++, iterator1X++)
            {
                SetConsoleTextAttribute (h, FOREGROUND_INTENSITY|FOREGROUND_GREEN);

                if (Matrix [iterator2Y][iterator1X] == Fruit)
                {
                    SetConsoleTextAttribute (h, FOREGROUND_RED);
                }
                printf("%c",Matrix [iterator2Y][iterator1X] );

            }   */

            CursurPos(cmmdPromptDis + 3 + Width, cmmdPromptDisH + 2 + iterator2Y);

             SetConsoleTextAttribute (h, FOREGROUND_BLUE|FOREGROUND_RED);

             printf ("%c %c", (char)219u, (char)219u);

             printf ("\n"); Dis(); iterator1X = 0;
        }
            iterator2Y = 0;

    MatrixBound2();

}

bool MatrixDisAllowOnce = true;

void DisplayMatrixContinous()
{
    int y = 1 + Height + cmmdPromptDisH; int x = 2 + Width + cmmdPromptDis;

    int iterator1X = 0, iterator2Y = 0;

    CursurPos (3 + cmmdPromptDis, 2 + cmmdPromptDisH);

   for (int iY = 2 + cmmdPromptDisH; iY <= y; iY++, iterator2Y++)
   {
       for (int iX = 3 + cmmdPromptDis; iX <= x; iX++, iterator1X++)
    {
        CursurPos (iX, iY);

        if (Matrix [iterator2Y][iterator1X] == Fruit)
        {
            SetConsoleTextAttribute (h, FOREGROUND_RED);
        }
        else
        {
            SetConsoleTextAttribute (h, FOREGROUND_INTENSITY|FOREGROUND_GREEN);
        }

        printf("%c",Matrix [iterator2Y][iterator1X] );
    }

    SetConsoleTextAttribute (h, FOREGROUND_BLUE|FOREGROUND_RED);

    iterator1X = 0;
   }
iterator2Y = 0;
}

void PlayerDeath()
{
    bSFinstance.touchingSegments();

    if (X > (Width - 1) || X < 0 || Y > (Height - 1) || Y < 0)
    {
        GameOver = true;
        ProgramEsc = true;
    }
}

void Setup()
{
    MatrixDisplaySetup();

    if (!once)
    {
        once = true;

        MatrixDisplay();
    }
    else
    {
       DisplayMatrixContinous();

       bSFinstance.snakeGrowth(bodySegmentsAfterHead);

       PlayerDeath();
    }

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
 if (UserInput == 119 && holdUserValue != 115) {Y--; holdUserValue = 119; verifyInput++;}
 else if (UserInput == 119 && holdUserValue == 115) {Y++;}

if (UserInput == 115 && holdUserValue != 119) {Y++; holdUserValue = 115; verifyInput++;}
else if (UserInput == 115 && holdUserValue == 119) {Y--;}

if (UserInput == 97 && holdUserValue != 100) {X--; holdUserValue = 97; verifyInput++;}
else if (UserInput == 97 && holdUserValue == 100) {X++;}

if (UserInput == 100 && holdUserValue != 97) {X++; holdUserValue = 100; verifyInput++;}
else if (UserInput == 100 && holdUserValue == 97) {X--;}
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
 PlayerDeath();

 ControlLogic();

 FruitCoords();

}

Menu titleInstance;

void Menu()
{
    while(!GameStart)
       {
           titleInstance.displayTitle();

           titleInstance.menuControl();
       }
}


int main()
{
    Menu();

while (!ProgramEsc)
  {
    while (!GameOver)
    {
        Logic();
        Setup();

    if (X == fruitX && Y == fruitY)
    {
        FruitCoordsVerify = false;
        FruitPresent = false;
    }

     Sleep(prgmDelay);
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
