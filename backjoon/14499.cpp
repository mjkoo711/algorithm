#include <iostream>
#include <queue>

using namespace std;
int arr[21][21] = {-1, };

class Dice{
  public:
  int location[7];
  public: 
  Dice() {
    for(int i=1; i<7; i++) {
      this->location[i] = 0;
    }
  }
  void left() {
    queue<int> q;
    q.push(this->location[6]); q.push(this->location[3]); q.push(this->location[1]); q.push(this->location[4]); 
    this->location[3] = q.front(); q.pop();
    this->location[1] = q.front(); q.pop();
    this->location[4] = q.front(); q.pop();
    this->location[6] = q.front(); q.pop();
  }

  void right() {
    queue<int> q;
    q.push(this->location[3]); q.push(this->location[1]); q.push(this->location[4]); q.push(this->location[6]);
    this->location[6] = q.front(); q.pop();
    this->location[3] = q.front(); q.pop();
    this->location[1] = q.front(); q.pop();
    this->location[4] = q.front(); q.pop();
  }

  void up() {
    queue<int> q;
    q.push(this->location[2]); q.push(this->location[1]); q.push(this->location[5]); q.push(this->location[6]);
    this->location[6] = q.front(); q.pop();
    this->location[2] = q.front(); q.pop();
    this->location[1] = q.front(); q.pop();
    this->location[5] = q.front(); q.pop();

  }
  void down() {
    queue<int> q; 
    q.push(this->location[2]); q.push(this->location[1]); q.push(this->location[5]); q.push(this->location[6]);
    this->location[1] = q.front(); q.pop();
    this->location[5] = q.front(); q.pop();
    this->location[6] = q.front(); q.pop();
    this->location[2] = q.front(); q.pop();
  }
};

int main() {
  int row, col; cin >> row >> col;
  int curX, curY; cin >> curX >> curY;
  int testCase; cin >> testCase;
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  Dice dice = Dice();

  for (int i=0; i<row; i++) {
    for (int j=0; j<col; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i=0; i<testCase; i++) {
    int direction; cin >> direction;

    if (direction == 1) {
      if (curY+1 >= col) continue;
      dice.right();
      if (arr[curX][curY+1] == 0) arr[curX][curY+1] = dice.location[6];
      else {
        dice.location[6] = arr[curX][curY+1]; 
        arr[curX][curY+1] = 0;
      }
      curY += 1;
      cout << dice.location[1] << endl;
    } else if (direction == 2) {
      if (curY-1 < 0) continue;

      dice.left();
      if (arr[curX][curY-1] == 0) arr[curX][curY-1] = dice.location[6];
      else {
        dice.location[6] = arr[curX][curY-1];
        arr[curX][curY-1] = 0;
      }
      curY -= 1;
      cout << dice.location[1] << endl;
    } else if (direction == 3) {
      if (curX-1 < 0) continue;
      dice.up();
      if (arr[curX-1][curY] == 0) arr[curX-1][curY] = dice.location[6];
      else {
        dice.location[6] = arr[curX-1][curY];
        arr[curX-1][curY] = 0;
      }
      curX -= 1;
      cout << dice.location[1] << endl;
    } else if (direction == 4) {
      if (curX+1 >= row) continue;
      dice.down();
      if (arr[curX+1][curY] == 0) arr[curX+1][curY] = dice.location[6];
      else {
        dice.location[6] = arr[curX+1][curY];
        arr[curX+1][curY] = 0;
      }
      curX += 1;
      cout << dice.location[1] << endl;
    }
  }
  return 0;
}