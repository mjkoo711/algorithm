#include <iostream>
#include <vector>
using namespace std;
int board[21][21];
int n;
int ans = -1123456789;

void solve(int cnt);

void findMax(int board[21][21]) {
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      ans = max(ans, board[i][j]);
    }
  }
}

void removeZero(vector<int> &vec) {
  int size = vec.size();
  for (int i=0; i<size-1; i++) {
    if (vec[i] != 0) continue;
    for (int j=i+1; j<size; j++) {
      if (vec[j] != 0) {
        swap(vec[i], vec[j]);
        break;
      }
    }
  }
}

void calculate(vector<int> &vec) {
  int size = vec.size();
  for (int i=0; i<size-1; ) {
    if (vec[i] == 0) {i++; continue;}
    for (int j=i+1; j<size; j++) {
      if (vec[j] == 0) { i++; continue; }
      if (vec[i] == vec[j]) {
        vec[i] += vec[j]; 
        vec[j] = 0;
        i = j+1; break;
      } else {
        i++; break;
      }
    }
  }
}

void left(int cnt) {
  for (int i=0; i<n; i++) {
    vector<int> vec;
    for (int j=0; j<n; j++) vec.push_back(board[i][j]);
    removeZero(vec);
    calculate(vec);
    removeZero(vec);
    for (int j=0; j<n; j++) board[i][j] = vec[j];
  }
  solve(cnt);
}

void right(int cnt) {
  for (int i=0; i<n; i++) {
    vector<int> vec;
    for (int j=n-1; j>=0; j--) vec.push_back(board[i][j]);
    removeZero(vec);
    calculate(vec);
    removeZero(vec);
    for (int j=n-1; j>=0; j--) board[i][j] = vec[n-(j+1)];
  }
  solve(cnt);
}

void up(int cnt) {
  for (int j=0; j<n; j++) {
    vector<int> vec;
    for (int i=0; i<n; i++) vec.push_back(board[i][j]);
    removeZero(vec);
    calculate(vec);
    removeZero(vec);
    for (int i=0; i<n; i++) board[i][j] = vec[i]; 
  }
  solve(cnt);
}

void down(int cnt) {
  for (int j=0; j<n; j++) {
    vector<int> vec;
    for (int i=n-1; i>=0; i--) vec.push_back(board[i][j]);
    removeZero(vec);
    calculate(vec);
    removeZero(vec);
    for (int i=n-1; i>=0; i--) board[i][j] = vec[n-(i+1)];
  }
  solve(cnt);
}

void restoreBoard(int copyBoard[21][21]) {
  for(int i=0; i<n; i++) 
    for (int j=0; j<n; j++)
      board[i][j] = copyBoard[i][j];
}

void solve(int cnt) {
  if (cnt == 5) {
    findMax(board);
    return;
  }
  int copyBoard[21][21];

  for(int i=0; i<n; i++) 
    for (int j=0; j<n; j++) 
      copyBoard[i][j] = board[i][j];
  
  left(cnt+1); restoreBoard(copyBoard);
  right(cnt+1); restoreBoard(copyBoard);
  up(cnt+1); restoreBoard(copyBoard);
  down(cnt+1); restoreBoard(copyBoard);
}

void change(int t[3]) {
  t[0] = 100;
}
int main() {
  cin >> n;

  for (int i=0; i<n; i++) 
    for (int j=0; j<n; j++) 
      cin >> board[i][j];

  solve(0);

  cout << ans << endl;
  return 0;
}