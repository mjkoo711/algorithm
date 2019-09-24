#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int arr[101][101];
int n;

int bfs(int height) {
  bool visited[101][101] = {false, };
  queue<pair<int, int> > q;
  int cnt = 0;

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (arr[i][j] > height && visited[i][j] == false) {
        q.push(make_pair(i, j));
        visited[i][j] = true;
        cnt++;
        
        while(!q.empty()) {
          pair<int, int> p = q.front(); q.pop();
          
          for (int k=0; k<4; k++) {
            int rx = p.first + dx[k];
            int ry = p.second + dy[k];
            if (rx < 0 || rx >= n || ry < 0 || ry >= n) continue;
            if (arr[rx][ry] > height && visited[rx][ry] == false) {
              q.push(make_pair(rx, ry));
              visited[rx][ry] = true;
            }
          }
        }
      }
    }
  }

  return cnt;
}

int main(){ 
  cin >> n;
  int maximum = 0;
  int ans = 0;

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> arr[i][j];
      maximum = max(maximum, arr[i][j]);
    }
  }

  for (int t = 0; t<=maximum; t++) {
    ans = max(bfs(t), ans);
  }

  cout << ans << endl;
  return 0;
}