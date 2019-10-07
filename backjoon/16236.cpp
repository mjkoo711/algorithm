#include <iostream>
#include <queue>

#define INF 401 // 20 * 20 보다 큰 값

using namespace std;
struct Point {
  int r, c, d; // row, col, distance
};

int n, map[20][20];
int sharkRow, sharkCol;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int start(int row, int col) {
  int ans = 0;
  int size = 2, eatCnt = 2; 
  Point bestPnt = {row, col, 0}; //최단 거리의 물고기 찾는 변수

  do {
    // 최단거리 찾기 bfs
    bool visited[20][20] = {false};
    queue<Point> q;
    visited[bestPnt.r][bestPnt.c] = true;
    q.push({bestPnt.r, bestPnt.c, 0}); // 최초엔 상어 이동거리 0 
    bestPnt.d = INF; // bestPnt.d에는 가장 가까운 물고기의 위치를 저장할 것 

    while (!q.empty()) {
      Point cur = q.front(); q.pop();

      if (cur.d > bestPnt.d) break; // 지금 있는 위치가 더 거리가 커지면 더이상 탐색할 필요가 없다. (더가까운 물고기 찾을 수 없기 때문에)
      if (map[cur.r][cur.c] > size) continue; // 현재 위치에 상어보다 큰 물고기가 있다고 하면, PASS
      if (map[cur.r][cur.c] != 0 && map[cur.r][cur.c] < size) { // 먹을 수 있는 물고기 찾았다!!! 
        if (cur.d < bestPnt.d) bestPnt = cur; // 거리가 가까운 것이 발견되었다면,
        else if (cur.d == bestPnt.d) { // 거리를 새로 찾았는데,
          if (cur.r < bestPnt.r) bestPnt = cur; // 더 위에 있는 것으로 바꿔줌
          else if (cur.r == bestPnt.r && cur.c < bestPnt.c) bestPnt = cur; // 더 왼쪽에 있는것으로 바꿔줌 
        }
        continue; // 가까운 물고기 찾았기에 더 멀리있는거 할 필요없어서 SKIP &&
      } 

      for (int i=0; i<4; i++) {
        int rx = cur.r + dx[i], ry = cur.c + dy[i];
        if (rx < 0 || rx >= n || ry < 0 || ry >= n) continue;
        if (visited[rx][ry]) continue;
        visited[rx][ry] = true;
        q.push({rx, ry, cur.d+1});
      } 
    }

    if (bestPnt.d != INF) { // 먹을수 있는 물고기가 있는 경우
      ans += bestPnt.d; 
      --eatCnt;
      if(eatCnt == 0) { // 상어 크기만큼 물고기 꺼억
        ++size;
        eatCnt = size;
      }
      map[bestPnt.r][bestPnt.c] = 0; //먹은 위치는 지워줌
    }
  } while(bestPnt.d != INF);
  
  return ans;
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> map[i][j];
      if (map[i][j] == 9) {
        sharkRow = i, sharkCol = j;
        map[i][j] = 0;
      }
    }
  }

  cout << start(sharkRow, sharkCol) << endl;
  return 0;
}