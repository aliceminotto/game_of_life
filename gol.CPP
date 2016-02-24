#include <iostream>
using namespace std;

int CountNeigh( const int& matrice[], const int& posizione[] ) {
    int counter = 0;
    if ( matrice[posizione[0]-1][posizione[1]-1] == 1 ) { counter++; }
    if ( matrice[posizione[0]-1][posizione[1]] == 1 ) { counter++; }
    if ( matrice[posizione[0]-1][posizione[1]+1] == 1 ) { counter++; }
    if ( matrice[posizione[0]][posizione[1]-1] == 1 ) { counter++; }
    if ( matrice[posizione[0]][posizione[1]+1] == 1 ) { counter++; }
    if ( matrice[posizione[0]+1][posizione[1]-1] == 1 ) { counter++; }
    if ( matrice[posizione[0]+1][posizione[1]] == 1 ) { counter++; }
    if ( matrice[posizione[0]+1][posizione[1]+1] == 1 ) { counter++; }
    return counter;
}

int main () {
int UNDER = 2;
int OVER = 3;
int REPR = 3;
int WIDTH = 20;
int HEIGHT = 20;

int canvas [ HEIGHT ][ WIDTH ];

for ( var i = 0; i < 10; i++) {
    int new_canvas [ HEIGHT ][ WIDTH ];
    for ( var j = 0; j < HEIGHT*WIDTH; j++) {
        new_canvas[j/WIDTH][j%WIDTH]; //considerig this
        CountNeigh(canvas,position); //define function that ount neigh and return counter
    };
};
}
