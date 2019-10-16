#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 50;
const int INF = 987654321;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m, result;
bool flag;
int arr[MAX][MAX], copyArr[MAX][MAX];
vector<pair<int, int> > virus;
vector<int> temp;

void copyArray(int a[50][50], int b[50][50]);
void BFS(int cnt);

int main() {
  int emptyCnt = 0; // 빈칸 개수
  cin >> n >> m;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 2) virus.push_back(make_pair(i, j));
      if (arr[i][j] == 0) emptyCnt++;
    }
  }

  sort(virus.begin(), virus.end());
  result = INF;

  temp.resize(virus.size(), 0); 
  for (int i=0; i<m; i++) temp[i] = 1; 
  sort(temp.begin(), temp.end());

  do {
    BFS(emptyCnt);
  } while(next_permutation(temp.begin(), temp.end()));
  
  if (!flag) cout << -1 << endl;
  else cout << result << endl;

  return 0;
}

void BFS(int cnt) {
  copyArray(copyArr, arr);

  queue<pair<int, int> > q;
  for (int i=0; i<temp.size(); i++) {
    if (temp[i]) { // 활성화 바이러스
      q.push(virus[i]);
      copyArr[virus[i].first][virus[i].second] = 3;
    }
  }

  int time = 0;
  while (!q.empty()) {
    int size = q.size();
    if (cnt == 0) {
      flag = true;
      result = min(result, time);
      break;
    }

    time++;
    for (int i=0; i<size; i++) {
      int x = q.front().first, y = q.front().second; q.pop();
      
      for (int k=0; k<4; k++) {
        int rx = x + dx[k], ry = y + dy[k];
        if (rx < 0 || rx >= n || ry < 0 || ry >= n) continue;
        if (copyArr[rx][ry] == 0 || copyArr[rx][ry] == 2) {
          if (copyArr[rx][ry] == 0) cnt--;
          copyArr[rx][ry] = 3;
          q.push(make_pair(rx, ry));
        }
      }
    }
  }
}

void copyArray(int a[50][50], int b[50][50]) {
  for (int i=0; i<MAX; i++) {
    for (int j=0; j<MAX; j++) {
      a[i][j] = b[i][j];
    }
  }
}