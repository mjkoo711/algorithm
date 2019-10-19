#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
  int x, y, num, dir;
};

int n, m, k;
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
vector<int> map[100][100];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int test; cin >> test;
  for (int t=1; t<=test; t++) {
    cin >> n >> m >> k; // 셀의 개수, 격리시간, 미생물 군집수
    vector<Node> v(k);

    for (int i=0; i<k; i++) {
      cin >> v[i].x >> v[i].y >> v[i].num >> v[i].dir;
      map[v[i].x][v[i].y].push_back(i); //map에 미생물군집 idx추가
    }

    while(m--) {
      // 군집 삭제
      for (int i=0; i<k; i++) {
        if (v[i].num == 0) continue;
        map[v[i].x][v[i].y].clear();
      }

      //군집이동
      for (int i=0; i<k; i++) {
        if (v[i].num == 0) continue;
        v[i].x += dx[v[i].dir];
        v[i].y += dy[v[i].dir];
        map[v[i].x][v[i].y].push_back(i);
      }

      for (int i=0; i<k; i++) {
        if (v[i].num == 0) continue;

        // 가장자리에 닿은 경우
        if (v[i].x == 0 || v[i].y == 0 || v[i].x == n-1 || v[i].y == n-1) {
          v[i].num /= 2; // 미생물 감소
          if (v[i].dir == 1) v[i].dir = 2;
          else if (v[i].dir == 2) v[i].dir = 1;
          else if (v[i].dir == 3) v[i].dir = 4;
          else v[i].dir = 3;
        } else if (map[v[i].x][v[i].y].size() > 1) { //여러 군집이 뭉친 경우
          int x = v[i].x, y = v[i].y;
          int maxNum=0, maxDir=0, maxIdx=0, sum=0;
          for (int i=0; i<map[x][y].size(); i++) {
            sum += v[map[x][y][i]].num; 
            if (maxNum < v[map[x][y][i]].num) {
              maxNum = v[map[x][y][i]].num;
              maxDir = v[map[x][y][i]].dir;
              maxIdx = map[x][y][i];
            }
            v[map[x][y][i]].num = 0;
          }
          v[maxIdx].num = sum;
          v[maxIdx].dir = maxDir;
        }
      }
    }

    //남은 미생물
    int ret = 0;
    for (int i=0;i<k; i++) ret += v[i].num;

    for (int i=0; i<n; i++) 
      for (int j=0; j<n; j++) 
        map[i][j].clear();

    cout << '#' << t << " " << ret << endl;
  }
  return 0;
}