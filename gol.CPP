#include <vector>
#include <iostream>
#include <utility> //for pairs
#include <sstream>
#include <string>
using namespace std;

int CountNeigh(const vector<vector<int> >& matrice , const pair <int,int>& posizione ) {
    int counter = 0;
    int row = posizione.first;
    int col = posizione.second;
    int HEIGHT = matrice.size();
    // << "size" << HEIGHT << "\n";
    int WIDTH = matrice[0].size();
    if ( row-1 >= 0 ){
        if ( col-1 >= 0 && matrice[row-1][col-1] == 1 ) { counter++; }
        if ( matrice[row-1][col] == 1 ) { counter++; }
        if ( col+1 < WIDTH && matrice[row-1][col+1] == 1 ) { counter++; }
    }
    if ( col-1 >= 0 && matrice[row][col-1] == 1 ) { counter++; }
    if ( col+1 < WIDTH && matrice[row][col+1] == 1 ) { counter++; }
    if ( row+1 < HEIGHT ) {
        if ( col-1 >= 0 && matrice[row+1][col-1] == 1 ) { counter++; }
        if ( matrice[row+1][col] == 1 ) { counter++; }
        if ( col+1 < WIDTH && matrice[row+1][col+1] == 1 ) { counter++; }
    }
    return counter;
}

void PrintCanvas(vector<vector<int> > canvas) {
    int HEIGHT = canvas.size();
    int WIDTH =  canvas[0].size();
    for ( int x = 0; x < HEIGHT; x++) {
        for ( int xx = 0; xx < WIDTH; xx++) {
            if (canvas[x][xx] == 0) {
                cout << "-"<< " ";
            } else {
                cout << "*"<< " ";
            }
            //cout << canvas[x][xx]<< " ";
            if (xx == WIDTH-1){
                cout << "\n";
            }
        }
        if ( x == HEIGHT-1 ){
            cout << "================" <<"\n";
        }
    }
}

int CheckNum() {
    int var;
    while (!(cin >> var )) {
        cout << "bad input" << "\n";
        cin.clear();
        cin.ignore( 1000, '\n');
    }
    return var;
}

int main () {
    string input;
    cout << "enter underpopulation {default would be 2} "<<"\n";
    //getline(cin,input);
    //int UNDER = stoi(input);
    int UNDER = CheckNum();
    while ( UNDER < 0 || UNDER > 9) {
        cout << "underpopulation must be between 0 and 9"<< "\n";
        UNDER = CheckNum();
    }
    cout << "enter overpopulation {default would be 3}"<<"\n";
    //getline(cin,input);
    //int OVER = stoi(input);
    int OVER = CheckNum();
    while ( OVER < UNDER || OVER > 9) {
        cout << "overpopulation must be between " << UNDER << " and 9" << "\n";
        OVER = CheckNum();
    }
    cout << "enter reproduction case {default would be 3}"<<"\n";
    //getline(cin,input);
    //int REPR = stoi(input);
    int REPR = CheckNum();
    while ( REPR < UNDER || REPR > OVER ) {
        cout << "reproduction must happen between " << UNDER << " and " << OVER << "\n";
        REPR = CheckNum();
    }
    cout << UNDER<<" " << OVER << " " << REPR << "\n";
    int WIDTH = 20;
    int HEIGHT = 20;

    vector<vector<int> > canvas (HEIGHT, vector<int>(WIDTH, 0));
    int situation;

    //input alive cells
    cout << "enter position of cell as N N, press q when finished"<<"\n";
    cout << "the first number must be between 1 and "<<HEIGHT<<"\n";
    cout << "the second number must be between 1 and "<<WIDTH<<"\n";
    int row, col;
    char q;
    do {
        while (! (cin >> row >> col)) { //enter the loop if that fails?
            cout << "the inputs must be 2 numbers"<<"\n";
            cin.clear(); //reset failure flag
            cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
        }
        //cin >> row >> col;
        canvas[row-1][col-1] = 1;
        cout << "press q or Q to exit, any other key to continue" <<"\n";
        cin >> q;
    } while (q != 'q' && q!='Q');

    PrintCanvas(canvas);

    for ( int i = 0; i < 10; i++) { //number of iteration, ideally infinite
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
