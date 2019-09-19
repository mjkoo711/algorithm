#include <iostream>
using namespace std;
char arr[51][51] = {' ', };

int check(int i, int j) {
  char start = arr[i][j];
  int count = 0;

  for (int x=i; x<i+8; x++) {
    for (int y=j; y<j+8; y++) {
      
      if (((x+y)%2) == 0) {
        if (arr[x][y] != start) count++;
      } else {
        if (arr[x][y] == start) count++;
      }
    }
  }
  return count;
}

int main() {
  int row, col; cin >> row >> col;
  int answer = 65;

  for (int i=0; i<row; i++) {
    for (int j=0; j<col; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i=0; i<=row-8; i++) {
    for (int j=0; j<=col-8; j++) {
      int result = check(i, j);
      result = (64-result) < result ? 64-result : result;
      if (result < answer) {
        answer = result;
      }
    }
  }
  cout << answer << endl;

  return 0;
}