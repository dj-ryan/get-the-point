 
#include<iostream>  

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27


  
using namespace std; 

class Entity 
{
    public:
        int y;
        int x;
        char value;
    Entity(int yVal, int xVal, char charValue) {
        y = yVal;
        x = xVal;
        value = charValue;
    }
    setPos(int yVal, int xVal) {
        y = yVal;
        x = xVal;
        return 0;
    }
};


void mPrint(char *arr, int n, int m, Entity player, Entity point) 
{ 
    int i, j; 
    for (i = 0; i < n; i++) {
    cout<<endl; 
      for (j = 0; j < m; j++)
        if (player.y == i && player.x == j) {
            printf("%c ", player.value); 
        } else if (point.y == i && point.x == j) {
            printf("%c ", point.value);
        } else {
            printf("%c ", *((arr+j*n) + i));
        }
    }
    cout<<endl;
}







int main() 
{ 
    int m, n;
    printf("===================================== \nWelcome to Get the point!\n=====================================\n");
    printf("RUlES:\n 1. Get points\n");
    printf("Arena Size? \nPlease enter X value: ");
    cin >> m;
    printf("Please Enter Y value: ");
    cin >> n;
    printf("\n");

    // size
    //int m = 10;
    //int n = 10;

    /* initialize random seed: */
    srand(time(NULL));

    /* generate random number between 1 and 10: */
    int randX = rand() % m;
    int randY = rand() % n;

    Entity player(0,0, 'X'); 
    Entity point(randY, randX, '#');

    char matrix[n][m];
    // initialize matrix with '.'s
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            matrix[i][j] = '.';
        }
    }

  
    mPrint(&matrix[0][0], n, m, player, point); 

    int KB_code=0;
    int pointCounter = 0;

   while(KB_code != KB_ESCAPE )
   { 
     if (kbhit())
      {
            KB_code = getch();

            if (KB_code != 224) {
                printf("Score: %d \n", pointCounter);
                switch (KB_code)
                {
                    case KB_LEFT:
                        player.x -= 1;
                    break;
                    case KB_RIGHT:
                        player.x += 1;                
                    break;

                    case KB_UP:
                        player.y -= 1;                     
                    break;

                    case KB_DOWN:
                        player.y += 1;                     
                    break;
                }
                mPrint(&matrix[0][0], n, m, player, point);

                if (player.y == point.y && player.x == point.x) {
                    pointCounter++;
                    randX = rand() % m;
                    randY = rand() % n;
                    point.setPos(randY, randX);
                    printf("Score: %d \n", pointCounter);
                    mPrint(&matrix[0][0], n, m, player, point);
                }
            }        
      }
  }


    return 0; 
} 