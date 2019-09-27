#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dp[501][501];
int arr[501][501];

int row, col;

int dfs(int x, int y) {
  if (x < 0 || x >= row || y < 0 || y >= col) return 0;
  if (dp[x][y] != -1) return dp[x][y];
  if (x == 0 && y == 0) return 1;
  dp[x][y] = 0;
  for (int i=0; i<4; i++) {
    int rx = x + dx[i];
    int ry = y + dy[i];

    if (arr[rx][ry] > arr[x][y]) {
      dp[x][y] += dfs(rx, ry);
    }
  }
  return dp[x][y];
}

int main() {
  cin >> row >> col;
  memset(dp, -1, sizeof(dp)); // <memory.h>를 추가해야함.
  for (int i=0; i<row; i++) 
    for (int j=0; j<col; j++) 
      cin >> arr[i][j];

  cout << dfs(row-1, col-1) << endl;
  return 0;
}