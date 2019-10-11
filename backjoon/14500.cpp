#include <iostream>
#include <vector>

using namespace std;
int row, col;
int ans = -1123456789;
int arr[501][501];
bool visited[501][501] = {false, };
vector<pair<int, int> > vec;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int r, int c, int blockCnt, int sum) {
  if (blockCnt == 4) {
    ans = max(sum, ans);
    return; 
  }
  visited[r][c] = true; 
  vec.push_back(make_pair(r, c));

  for (int i=0; i<vec.size(); i++) {
    for (int k=0; k<4; k++) {
      int rx = vec[i].first + dx[k];
      int ry = vec[i].second + dy[k];
      if (rx < 0 || rx >= row || ry < 0 || ry >= col) continue;
      if (visited[rx][ry] == false) 
        dfs(rx, ry, blockCnt+1, sum + arr[rx][ry]);
    }
  }

  visited[r][c] = false; vec.pop_back();
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> row >> col;

  for (int i=0; i<row; i++) 
    for (int j=0; j<col; j++) 
      cin >> arr[i][j];


  for (int i=0; i<row; i++)
    for (int j=0; j<col; j++) 
      dfs(i, j, 1, arr[i][j]);

  cout << ans << endl;
  return 0;
}