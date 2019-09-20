#include <iostream>
#include <queue>

using namespace std;
char arr[101][101] = {'0', };
bool visited[101][101] = {false, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int row, col;

struct Location {
  int x,y;
  Location(int x, int y): x(x), y(y) {}
};

void BFS(int a, int b) {
  queue<pair<Location, int> > q;

  q.push(make_pair(Location(a, b), 1));
  visited[a][b] = true;

  while (!q.empty()) {
    pair<Location, int> p = q.front(); q.pop();
    if (p.first.x == row && p.first.y == col) {
      cout << p.second << endl;
      return;
    }
    for (int i=0; i<4; i++) {
      int newX = p.first.x+dx[i];
      int newY = p.first.y+dy[i];

      if (newX < 1 || newX > row || newY < 1 || newY > col) continue;
      if (arr[newX][newY] == '1' && visited[newX][newY] == false) {
        q.push(make_pair(Location(newX, newY), p.second+1));
        visited[newX][newY] = true;
      }
    }
  }
}

int main() {
  cin >> row >> col;

  for (int i=1; i<=row; i++) {
    for (int j=1; j<=col; j++) {
      cin >> arr[i][j];
    }
  }

  BFS(1,1);

  return 0;
}