#include <iostream>
using namespace std;
int n, m, r, c, d;
int arr[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;

int main() {
  cin >> n >> m >> r >> c >> d;
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) 
      cin >> arr[i][j];

  bool flag = true;
  while (flag) {
    if (arr[r][c] == 0) {
      arr[r][c] = 2;
      ans++;
    }

    int i;
    for (i=0; i<4; i++) { 
      d = d-1 < 0 ? 3 : d-1; 
      int nr = r + dx[d], nc = c + dy[d];
      if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
      if (arr[nr][nc] == 0) {
        r = nr, c = nc; 
        break;
      }
    }
    
    if (i==4) {
      if (d==0) r++;
      else if (d==1) c--;
      else if (d==2) r--;
      else if (d==3) c++;

      if (arr[r][c] == 1) flag = false;
    }
  }

  cout << ans << endl; 
  return 0;
}