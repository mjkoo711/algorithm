#include <iostream>
using namespace std;

struct Matrix {
  int arr[3][3]; 
};

int main() {
  Matrix matrix[3][3];

  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      cin >> matrix[i/3][j/3].arr[i%3][j%3];
    }
  }

  
  return 0;
}