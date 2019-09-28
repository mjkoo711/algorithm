#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dh[2] = {1, -1};

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
        for (int a=0; a<4; a++) {
          int rx = i + dx[a];
          int ry = j + dy[a];
          if (rx < 0 || rx >= row || ry < 0 || ry >= col) continue;
          if (tomato[rx][ry][h] == 0 && tomato[i][j][h] == 1 && visited[i][j][h] == false) {
            q.push(Location(i, j, h, 0));
            visited[i][j][h] = true;
          }
        }
        for (int a=0; a<2; a++) {
          int rh = h + dh[a];
          if (rh < 0 || rh >= height) continue;
          if (tomato[i][j][rh] == 0 && tomato[i][j][h] == 1 && visited[i][j][h] == false) {
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
    
    //location 주위에 0이 있는 것을 1로 바꾼 뒤에 visited도 true로 하고 1로 바꾼 위치를 q에 또 집어넣기
    for (int i=0; i<4; i++) {
      int rx = x + dx[i];
      int ry = y + dy[i];
      if (rx < 0 || rx >= row || ry < 0 || ry >= col) continue;
      if (tomato[rx][ry][h] == 0 && visited[rx][ry][h] == false) {
        tomato[rx][ry][h] = 1;
        visited[rx][ry][h] = true;
        q.push(Location(rx, ry, h, location.day+1));
        day = max(day, location.day+1);
        zeroCnt--;
      }
    }

    for (int i=0; i<2; i++) {
      int rh = h + dh[i];
      if (rh < 0 || rh >= height) continue;
      if (tomato[x][y][rh] == 0 && visited[x][y][rh] == false) {
        tomato[x][y][rh] = 1;
        visited[x][y][rh] = true;
        q.push(Location(x, y, rh, location.day+1));
        day = max(day, location.day+1);
        zeroCnt--;
      }
    }
  }
  if (zeroCnt > 0) cout << -1 << endl;
  else cout << day << endl;
  return 0;
}