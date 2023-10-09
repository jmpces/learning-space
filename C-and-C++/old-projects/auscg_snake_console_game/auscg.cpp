#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cctype>
#include <string>
using namespace std;

#define LENGTH 20
#define WIDTH 40
#define SNAKE_LENGTH 50  // primary set to 5 original value is 30

string te;
int headX = WIDTH/2, headY = LENGTH/2;
int xTail[SNAKE_LENGTH], yTail[SNAKE_LENGTH];
int xT[SNAKE_LENGTH], yT[SNAKE_LENGTH];
int foodX, foodY;
int snakeBody = 1;  // primary set to 5    original value is 1
int tmpA, tmpB, tmp1, tmp2;

void addd();

void setup()
{
    for(int i = 0; i < SNAKE_LENGTH; i++)
    {
        xTail[i] = 21+i;
        yTail[i] = 10;

        xT[i] = xTail[i];
        yT[i] = yTail[i];
    }
}

void gameOV_disp();

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
int score = 0;

void wait(int x)
{
    for(int i = 0; i < 100000*x; i++)
        ;
}
inline void cls() // Clear screen
{
    system("cls");
}
inline void locate(int x, int y) // Put cursor in row z
{
    // and column s
    cout << "\033[" << y << ';' << x << 'H';
}

void draw()
{
    // draw
    for(int i = 0; i < LENGTH; i++)
    {
        locate(0,i), cout<<(char)219;
        locate(WIDTH,i), cout<<(char)219;
    }

    for(int i = 0; i < WIDTH+1; i++)
    {
        locate(i,0), cout<<(char)219;
        locate(i,LENGTH), cout<<(char)219;
    }
}

bool gameover();

stats()
{
    locate(50,3);
    cout<<"Score : "<<score;

}

void generateFood();
void eat();
void inputWASD();
void move_();
void snake();
//void tailGate();
int diff = 30;
int main()
{
  cout<<"controls : \n\t\tw - up, \n\t\ts - down \n\t\ta - left \n\t\td - right"<<endl<<endl;
  system("pause");
    do {

    headX = WIDTH/2;
    headY = LENGTH/2;

    if(te == "e")
    {
         score = 0;
         snakeBody = 1;
         diff = 30;
    }

    setup();
    cls();
    locate(1,1);
    draw();
    generateFood();
    just_message : {
     locate(65,3);
    cout<<"Console Snake Game : ";
    locate(65,4); cout<<"written in C++";
    locate(65,5); cout<<" : mords : ";
    }

    while(true)
    {
        addd();

        locate(foodX,foodY);
          cout<<(char)254;

        eat();
        inputWASD();

        //move_();
        snake();
        //tailGate();
        wait(10*diff);

        if(te != "e" && te != "~") { locate(70,18); system("pause"); te = "~"; locate(70,18);cout<<"                                   ";}

        if(gameover())
            break;
    }

    gameOV_disp();
    locate(10,18); cout<<"  W E A K !  ";
    locate(10,20); cout<<" Do you like to try again ? :  | \"q\" - quit | \"anything\" - Continue | \"e\" - New Game |\n\n\tInput ? : ";

     locate(10,24),cin>>te;

    } while(te != "q");


     system("pause");




    return 0;
}

void snake()
{

   // this sets the length of the snake it clears the body character of the snake
   // so that it will not draw permanently
    for(int i = 0; i < snakeBody; i++)
    {
        if(i == snakeBody-1){ locate(xTail[i],yTail[i]); cout<<' '; }
    }

    for(int i = 0; i < snakeBody; i++)
    {
        xT[i] = xTail[i];
        yT[i] = yTail[i];
    }

    xTail[0] = headX;
    yTail[0] = headY;

    for(int i = 0; i < snakeBody; i++)
    {
        xTail[i+1] = xT[(i)];
        yTail[i+1] = yT[(i)];
    }

    move_();

    locate(headX,headY); // 20,10
    cout<<((char)178);

    // snake body drawer
    locate(xTail[0],yTail[0]);
        cout<<((char)177);

}

void generateFood()
{
    foodX = ( rand() % ((WIDTH-1) - ( 2 - 1 ) ) ) + 2;
    foodY = ( rand() % ((LENGTH-1) - ( 2 - 1 ) ) ) + 2;

    if(snakeBody != 1) {
    for(int i = 0; i < snakeBody; i++)
    {
        if(foodX == xTail[i+1] && foodY == yTail[i+1])
            foodX += 1, foodY += 1;
    } }

    locate(foodX,foodY);
    cout<<(char)254;
}

void move_()
{
    switch(dir)
    {
    case UP:
        headY--;
        break;
    case DOWN:
        headY++;
        break;
    case LEFT:
        headX--;
        break;
    case RIGHT:
        headX++;
        break;
    }
}

bool gameover()
{
    // bool temp = false;
    if(snakeBody != 1) {
    for(int i = 0; i < snakeBody; i++)
    {
        if(headX == xTail[i+1] && headY == yTail[i+1])
            return true;
    } }

    if(headX == 1)
        return true;

    if(headX == 40)
        return true;

    if(headY == 1)
        return true;

    if(headY == 20)
        return true;

    else
        return false;
}

void inputWASD()
{
    if(_kbhit()) // set direction
    {
        switch(_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case '-':
            diff -= 5;
            break;
        case '=':
            diff += 5;
            break;
        }
    }
}

void eat()
{
    if(headX == foodX && headY == foodY)
    {
        generateFood();
        score = score + 1;
        snakeBody = snakeBody + 1;

        if(diff > 0) {
          diff -= 1;
        }

        stats();
    }
}

void gameOV_disp()
{
     cls();

     char q = (char)178;

     char x = ' ';
     char xx[] = "    ";

     locate(20,8);  cout<<q<<q<<q<<q<<xx<<x<<q<<q<<x<<xx<<q<<x<<x<<q<<xx<<q<<q<<q<<q;
     locate(20,9);  cout<<q<<x<<x<<x<<xx<<q<<x<<x<<q<<xx<<q<<q<<q<<q<<xx<<q<<x<<x<<x;
     locate(20,10); cout<<q<<x<<q<<q<<xx<<q<<q<<q<<q<<xx<<q<<q<<q<<q<<xx<<q<<q<<q<<q;
     locate(20,11); cout<<q<<x<<x<<q<<xx<<q<<x<<x<<q<<xx<<q<<x<<x<<q<<xx<<q<<x<<x<<x;
     locate(20,12); cout<<q<<q<<q<<q<<xx<<q<<x<<x<<q<<xx<<q<<x<<x<<q<<xx<<q<<q<<q<<q;

     locate(60,8);  cout<<q<<q<<q<<q<<xx<<q<<x<<x<<q<<xx<<q<<q<<q<<q<<xx<<q<<q<<q<<q;
     locate(60,9);  cout<<q<<x<<x<<q<<xx<<q<<x<<x<<q<<xx<<q<<x<<x<<x<<xx<<q<<x<<x<<q;
     locate(60,10); cout<<q<<x<<x<<q<<xx<<q<<x<<x<<q<<xx<<q<<q<<q<<q<<xx<<q<<q<<q<<q;
     locate(60,11); cout<<q<<x<<x<<q<<xx<<x<<q<<q<<x<<xx<<q<<x<<x<<x<<xx<<q<<x<<q<<x;
     locate(60,12); cout<<q<<q<<q<<q<<xx<<x<<q<<q<<x<<xx<<q<<q<<q<<q<<xx<<q<<x<<x<<q;

}

void addd() {

    if(snakeBody == 2)   {
          locate(50,8); cout<<"                                  ";
          locate(50,8); cout<<" pwede na "; }
    if(snakeBody == 4)   {
          locate(50,8); cout<<"                                  ";
          locate(50,8); cout<<" mabagal paren "; }
    if(snakeBody == 9)   {
          locate(50,8); cout<<"                                  ";
          locate(50,8); cout<<" hangan dyan ka na lng "; }
    if(snakeBody == 12)  {
          locate(50,8); cout<<"                                  ";
          locate(50,8); cout<<" Tyamba "; }
    if(snakeBody == 15) {
          locate(50,8); cout<<"                                  ";
          locate(50,8); cout<<" Himala lang yan "; }
    if(snakeBody == 20) {
          locate(50,8); cout<<"                                  ";
          locate(50,8); cout<<" wala tyamba parin "; }
    if(snakeBody == 25) {
          locate(50,8); cout<<"                                  ";
          locate(50,8); cout<<" Cheater wala na uwi na "; }
     if(snakeBody == 30) {
          locate(50,8); cout<<"                                  ";
          locate(50,8); cout<<" Continue pa ! weak "; }
     if(snakeBody == 40) {
          locate(50,8); cout<<"                                  ";
          locate(50,8); cout<<" Nakikita ka ng Dyos"; }
    }
