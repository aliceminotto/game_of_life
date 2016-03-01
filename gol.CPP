#include <vector>
#include <iostream>
using namespace std;

int CountNeigh(vector<vector<int> > matrice , int posizione[2] ) {
    int counter = 0;
    int row = posizione[0];
    int col = posizione[1];
    int HEIGHT = matrice.size();
    // << "size" << HEIGHT << "\n";
    int WIDTH = matrice[0].size();
    if ( row-1 >= 0 && col-1 >= 0 && matrice[row-1][col-1] == 1 ) { counter++; }
    if ( row-1 >= 0 && matrice[row-1][col] == 1 ) { counter++; }
    if ( row-1 >=0 && col+1 < WIDTH && matrice[row-1][col+1] == 1 ) { counter++; }
    if ( col-1 >= 0 && matrice[row][col-1] == 1 ) { counter++; }
    if ( col+1 < WIDTH && matrice[row][col+1] == 1 ) { counter++; }
    if ( row+1 < HEIGHT && col-1 >= 0 && matrice[row+1][col-1] == 1 ) { counter++; }
    if ( row+1 < HEIGHT && matrice[row+1][col] == 1 ) { counter++; }
    if ( row+1 < HEIGHT && col+1 < WIDTH && matrice[row+1][col+1] == 1 ) { counter++; }
    return counter;
}

int main () {
int UNDER = 2;
int OVER = 3;
int REPR = 3;
int WIDTH = 10;
int HEIGHT = 10;

vector<vector<int> > canvas (HEIGHT, vector<int>(WIDTH, 0));

//cout << canvas[0][0] <<"\n";

for ( int i = 0; i < 10; i++) {
    vector<vector<int> > new_canvas (HEIGHT, vector<int>(WIDTH, 0));
    for ( int j = 0; j < HEIGHT*WIDTH; j++) {
        //new_canvas[j/WIDTH][j%WIDTH]; //considerig this
        int position[] = {j/WIDTH, j%WIDTH};
        //cout << j/WIDTH;
        //cout << j%WIDTH;
        CountNeigh(canvas,position); //define function that ount neigh and return counter
    }
}
}
