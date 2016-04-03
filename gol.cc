#include "gol.h"

void Canvas::PrintCanvas() {
  int HEIGHT = vector_.size();
  int WIDTH =  vector_[0].size();
  for ( int x = 0; x < HEIGHT; x++) {
      for ( int xx = 0; xx < WIDTH; xx++) {
          if (vector_[x][xx] == 0) {
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
