#include <iostream>
#include <queue>
using namespace std;
char arr[1001][1001] = {'0', };
bool visited[1001][1001][2] = {false, }; 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Location {
  int x, y, chance;
  Location(int x, int y, int chance): x(x), y(y), chance(chance) {}
};

int main() {
  int row, col; cin >> row >> col;
  queue<pair<Location, int> > q;

  for (int i=0; i<row; i++) {
    for (int j=0; j<col; j++) {
      cin >> arr[i][j];
    }
  }


  int chance = 1;
  
  q.push(make_pair(Location(0, 0, 1), 1));
  visited[0][0][chance] = true;

  while (!q.empty()) {
    pair<Location, int> p = q.front(); q.pop();
    Location curLocation = p.first;
    int cnt = p.second;
    int chance = curLocation.chance;
    if (curLocation.x == row-1 && curLocation.y == col-1) {
      cout << cnt << endl; return 0;
    }

    for (int i=0; i<4; i++) {
      int rx = curLocation.x + dx[i];
      int ry = curLocation.y + dy[i];

      if (rx < 0 || rx >= row || ry < 0 || ry >= col) continue;
      if (visited[rx][ry][chance] == false) {
        if (arr[rx][ry] == '1' && curLocation.chance == 1) {
          visited[rx][ry][chance-1] = true;
          q.push(make_pair(Location(rx, ry, curLocation.chance-1), cnt+1));
        } 
        if (arr[rx][ry] == '0') {
          q.push(make_pair(Location(rx, ry, curLocation.chance), cnt+1));
          visited[rx][ry][chance] = true;
        }
      }
    }
  }

  cout << -1 << endl;
  return 0;
}