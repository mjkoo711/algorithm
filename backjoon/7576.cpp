#include <iostream>
#include <queue>
using namespace std;
int tomato[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int row, col;
int day = 0;
int tomatoCount = 0;

struct Location {
  int x, y; 
  Location(int x, int y): x(x), y(y) {}
};

queue<pair<Location, int> > q;

void BFS() {
  int lastDay;
  while(!q.empty()) {
    pair<Location, int> p = q.front(); q.pop();
    day++; lastDay = p.second;

    for (int i=0; i<4; i++) {
      int rx = p.first.x + dx[i];
      int ry = p.first.y + dy[i];
      if (rx < 0 || rx > row-1 || ry < 0 || ry > col-1) continue;
      if (tomato[rx][ry] == 0) {
        tomatoCount--;
        q.push(make_pair(Location(rx, ry), p.second+1));
        tomato[rx][ry] = 1;
      }
    }
  }

  if (tomatoCount > 0) cout << -1 << endl;
  else cout << lastDay << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> col >> row;

  for (int i=0; i<row; i++) {
    for (int j=0; j<col; j++) {
      cin >> tomato[i][j];
      if (tomato[i][j] == 0) tomatoCount++;
      if (tomato[i][j] == 1) {
        q.push(make_pair(Location(i, j), day));
      }
    }
  }

  BFS();
  return 0;
}