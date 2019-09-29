#include <iostream>
#include <queue>
using namespace std;
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

struct Location {
  int x, y, h;
  int day;
  Location(int x, int y, int h, int day): x(x), y(y), h(h), day(day) {}
};

int main() {
  int row, col, height; 
  int zeroCnt = 0;
  int day = 0;
  queue<Location> q;
  cin >> col >> row >> height;

  int tomato[row][col][height];
  bool visited[row][col][height];
  
  for (int h=0; h<height; h++) {
    for (int i=0; i<row; i++) {
      for (int j=0; j<col; j++) {
        cin >> tomato[i][j][h];
        visited[i][j][h] = false;
        if (tomato[i][j][h] == 0) zeroCnt++;
      }
    }
  }

  for (int h=0; h<height; h++) {
    for (int i=0; i<row; i++) {
      for (int j=0; j<col; j++) {
        for (int a=0; a<6; a++) {
          int rx = i + dx[a];
          int ry = j + dy[a];
          int rh = h + dh[a];
          if (rx < 0 || rx >= row || ry < 0 || ry >= col || rh < 0 || rh >= height) continue;
          if (tomato[rx][ry][rh] == 0 && tomato[i][j][h] == 1 && visited[i][j][h] == false) {
            q.push(Location(i, j, h, 0));
            visited[i][j][h] = true;
          }
        }
      }
    }
  }

  if (q.size() == 0) { cout << 0 << endl; return 0; }
  while(!q.empty()) {
    Location location = q.front(); q.pop();
    int x = location.x;
    int y = location.y;
    int h = location.h;
    
    for (int i=0; i<6; i++) {
      int rx = x + dx[i];
      int ry = y + dy[i];
      int rh = h + dh[i];
      if (rx < 0 || rx >= row || ry < 0 || ry >= col || rh < 0 || rh >= height) continue;
      if (tomato[rx][ry][rh] == 0 && visited[rx][ry][rh] == false) {
        tomato[rx][ry][rh] = 1;
        visited[rx][ry][rh] = true;
        q.push(Location(rx, ry, rh, location.day+1));
        day = max(day, location.day+1);
        zeroCnt--;
      }
    }
  }

  if (zeroCnt > 0) cout << -1 << endl;
  else cout << day << endl;
  return 0;
}