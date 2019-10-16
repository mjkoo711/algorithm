#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Point {
  int x, y;
  Point(int x, int y): x(x), y(y) {}
};

int n, m, spaceSize, virusSize, ans = -123456789;
int arr[9][9], copyArr[9][9];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<Point> spaces, viruses;
vector<int> spacePermute;

template <class T>
void copyArray(T a[9][9], T b[9][9]) {
  for (int i=0; i<9; i++) 
    for (int j=0; j<9; j++) 
      a[i][j] = b[i][j];
}

int countSafeArea() {
  int cnt = 0;
  for (int i=0; i<n; i++) 
    for (int j=0; j<m; j++) 
      if (copyArr[i][j] == 0) cnt++;
  return cnt;
}

void bfs() {
  copyArray(copyArr, arr);
  for (int i=0; i<spaceSize; i++) {
    if (spacePermute[i] == 1) {
      int x = spaces[i].x, y = spaces[i].y;
      copyArr[x][y] = 1;
    }
  }

  queue<Point> q;
  for (int i=0; i<virusSize; i++) {
    q.push(viruses[i]);
  }

  while (!q.empty()) {
    int size = q.size();

    while(size--) {
      Point p = q.front(); q.pop();
      
      for (int k=0; k<4; k++) {
        int rx = p.x + dx[k], ry = p.y + dy[k];
        if (rx < 0 || rx >= n || ry < 0 || ry >= m) continue;
        if (copyArr[rx][ry] == 0) {
          q.push(Point(rx, ry));
          copyArr[rx][ry] = 2;
        }
      }
    }
  }

  ans = max(ans, countSafeArea());
}

int main() { 
  cin >> n >> m;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 0) spaces.push_back(Point(i, j));
      else if (arr[i][j] == 2) viruses.push_back(Point(i, j));
    }
  }

  spaceSize = spaces.size();
  virusSize = viruses.size();
  spacePermute.resize(spaceSize, 0);
  for (int i=spaceSize-1; i>spaceSize-4; i--) spacePermute[i] = 1;

  do {
    bfs();
  } while(next_permutation(spacePermute.begin(), spacePermute.end()));
  
  cout << ans << endl;
  return 0;
}