#include <iostream>
using namespace std;

int CountNeigh(int matrice[][10][10], int posizione[2] ) {
    int counter = 0;
    int row = posizione[0];
    int col = posizione[1];
    if ( matrice[row-1][col-1] == 1 ) { counter++; }
    if ( matrice[row-1][col] == 1 ) { counter++; }
    if ( matrice[row-1][col+1] == 1 ) { counter++; }
    if ( matrice[row][col-1] == 1 ) { counter++; }
    if ( matrice[row][col+1] == 1 ) { counter++; }
    if ( matrice[row+1][col-1] == 1 ) { counter++; }
    if ( matrice[row+1][col] == 1 ) { counter++; }
    if ( matrice[row+1][col+1] == 1 ) { counter++; }
    return counter;
}

int main () {
int UNDER = 2;
int OVER = 3;
int REPR = 3;
int WIDTH = 10;
int HEIGHT = 10;

int canvas [ HEIGHT ][ WIDTH ];

for ( int i; i<HEIGHT; i++) {
    for ( int j; j<WIDTH; j++) {
        canvas[i][j] = 0;
    }
}

for ( int i = 0; i < 10; i++) {
    int new_canvas [ HEIGHT ][ WIDTH ];
    for ( int j = 0; j < HEIGHT*WIDTH; j++) {
        //new_canvas[j/WIDTH][j%WIDTH]; //considerig this
        int position[] = {j/WIDTH, j%WIDTH};
        cout << j/WIDTH;
        cout << j%WIDTH;
        cout << CountNeigh(canvas,position); //define function that ount neigh and return counter
    }
}
}
