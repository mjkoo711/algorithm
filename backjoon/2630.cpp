#include <iostream>
#define WHITE 0
#define BLUE 1
using namespace std;
int map[129][129];
int n, whiteCount = 0, blueCount = 0;

bool isFinish(int n, int r, int c) {
  int color = map[r][c];
  for (int i=r; i<r+n; i++) {
    for (int j=c; j<c+n; j++) {
      if (color != map[i][j]) return false;
    }
  }

  if (color == WHITE) whiteCount++;
  else if (color == BLUE) blueCount++;

  return true;
}

void solve(int n, int r, int c) {
  if (isFinish(n, r, c)) return;
  int dr[] = {r, r+(n/2), r, r+(n/2) };
  int dc[] = {c, c, c+(n/2), c+(n/2) };
  for (int i=0; i<4; i++) {
    solve(n/2, dr[i], dc[i]);
  }
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cin >> map[i][j];
    }
  }

  solve(n, 1, 1);

  cout << whiteCount << "\n" << blueCount << endl;
  return 0;
}