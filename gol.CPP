#include <vector>
#include <iostream>
#include <utility> //for pairs
#include <sstream>
#include <string>
using namespace std;

int CountNeigh(vector<vector<int> > matrice , pair <int,int> posizione ) {
    int counter = 0;
    int row = posizione.first;
    int col = posizione.second;
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

void PrintCanvas(vector<vector<int> > canvas) {
    int HEIGHT = canvas.size();
    int WIDTH =  canvas[0].size();
    for ( int x = 0; x < HEIGHT; x++) {
        for ( int xx = 0; xx < WIDTH; xx++) {
            cout << canvas[x][xx]<< " ";
            if (xx == WIDTH-1){
                cout << "\n";
            }
        }
        if ( x == HEIGHT-1 ){
            cout << "================" <<"\n";
        }
    }
}

int main () {
    string input;
    cout << "enter underpopulation {default would be 2} "<<"\n";
    getline(cin,input);
    int UNDER = stoi(input);
    cout << "enter overpopulation {default would be 3}"<<"\n";
    getline(cin,input);
    int OVER = stoi(input);
    cout << "enter reproduction case {default would be 3}"<<"\n";
    getline(cin,input);
    int REPR = stoi(input);
    int WIDTH = 10;
    int HEIGHT = 10;

    vector<vector<int> > canvas (HEIGHT, vector<int>(WIDTH, 0));
    int situation;
    //cout << canvas[0][0] <<"\n";

    //delete the following lines and add an input system
    canvas[5][3] = 1;
    canvas[1][7] = 1;
    canvas[1][2] = 1;
    canvas[3][2] = 1;
    canvas[5][2] = 1;
    PrintCanvas(canvas);

    for ( int i = 0; i < 2; i++) { //number of iteration, ideally infinite
        vector<vector<int> > new_canvas (HEIGHT, vector<int>(WIDTH, 0));
        for ( int j = 0; j < HEIGHT*WIDTH; j++) { //itearte over the matrix
            pair <int,int> position (j/WIDTH, j%WIDTH);
            //cout << j/WIDTH;
            //cout << j%WIDTH;
            situation = CountNeigh(canvas,position); //define function that count neigh and return counter
            if (situation < UNDER || situation > OVER) {
                new_canvas[position.first][position.second] = 0;
            } else if (situation == REPR) {
                new_canvas[position.first][position.second] = 1;
            } else {
                new_canvas[position.first][position.second] = canvas[position.first][position.second];
            }
        }
        canvas = new_canvas;
        PrintCanvas(canvas);
    }
}
