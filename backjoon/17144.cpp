#include <iostream>
#include <cstring>
#include <vector>
#define FIRST 0
#define SECOND 1
using namespace std;
struct Point {
  int r, c;
  Point(int r, int c): r(r), c(c) {}
};

vector<Point> machine;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};
int map[51][51], nextMap[51][51];
int r, c, t;

void spread() {
  memset(nextMap, 0, sizeof(nextMap));
  for (int i=1; i<=r; i++) {
    for (int j=1; j<=c; j++) {
      if (map[i][j] == -1) continue;
      int spreadValue = map[i][j] / 5; 
      for (int k=0; k<4; k++) {
        int nr = i + dr[k], nc = j + dc[k];
        if (nr < 1 || nr > r || nc < 1 || nc > c || map[nr][nc] == -1) continue;
        nextMap[nr][nc] += spreadValue;
        map[i][j] -= spreadValue;
      }
    }
  }

  for (int i=1; i<=r; i++) {
    for (int j=1; j<=c; j++) {
      map[i][j] += nextMap[i][j];
    }
  }
}

void clean(int nr, int nc, int area) {
  int tmp1 = 0, tmp2 = 0, dir = 0;

  while (!(nr==machine[area].r && nc==machine[area].c)) {
    tmp2 = map[nr][nc];
    map[nr][nc] = tmp1;
    tmp1 = tmp2;
    int tmp_r = nr + dr[dir], tmp_c = nc + dc[dir];
    if (tmp_r < 1 || tmp_r > r || tmp_c < 1 || tmp_c > c) {
      if (area == FIRST) dir = dir+1 > 3 ? 0 : dir+1;
      else if (area == SECOND) dir = dir-1 < 0 ? 3 : dir-1;
    }
    nr = nr + dr[dir], nc = nc + dc[dir];
  }

  map[machine[area].r][machine[area].c] = -1;
}

int main() {
  cin >> r >> c >> t;
  for (int i=1; i<=r; i++) {
    for (int j=1; j<=c; j++) {
      cin >> map[i][j];
      if (map[i][j] == -1) machine.push_back(Point(i, j));
    }
  }
  int time = 1;
  while (time++ <= t) {
    spread();
    for (int i=FIRST; i<=SECOND; i++) clean(machine[i].r, machine[i].c+1, i);
  }

  int sum = 0;
  for (int i=1; i<=r; i++)
    for (int j=1; j<=c; j++) 
      if (map[i][j] > 0) sum += map[i][j];
  cout << sum << endl;
  return 0;
}