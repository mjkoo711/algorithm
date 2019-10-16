#include <iostream>
#include <memory.h>
using namespace std;
int ladder[31][11] = {0, };
int n, m, h;
int ans = 4;

bool game(int arr[31][11]) {
  int cnt = 0;
  for (int i=1; i<=h; i++) { // 1번부터 h번까지 출발 위치
    int row = 1, col = i;

    while (row <= h) {
      if (arr[row][col] == 1) {
        // 왼쪽, 오른쪽 확인
        if (arr[row][col-1] == 1) { // 왼쪽으로 가야함
          row += 1;
          col -= 1;
        } else if (arr[row][col+1] == 1) { //오른쪽으로 가야함
          row += 1;
          col += 1;
        }
      } else {
        row += 1;
        // 아래로
      }
    }
    if (i == col) cnt++;
    if (cnt == h) return true; // cnt가 h개이면 전부다이기 때문에
  }
  return false;
}

void dfs(int count) {
  if (count >= ans) { ans = -1; return; }
  if (game(ladder)) {
    ans = count;
    return;
  }
  if (count == 3) return;
  cout << "kk" << endl;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<h; j++) {
      int flag = -1;
      if (ladder[i][j] == 1) continue;
      if (ladder[i][j-1] == 1) { flag = 0; ladder[i][j] = ladder[i][j+1] = 1; }
      else if (ladder[i][j+1] == 1) { flag = 1; ladder[i][j] = ladder[i][j-1] = 1; }
      dfs(count+1);
      if (flag == 0) { ladder[i][j] = ladder[i][j+1] = 0; }
      else if (flag == 1) { ladder[i][j] = ladder[i][j-1] = 0; }
    }
  }
}

int main() {
  cin >> n >> m >> h; 

  for (int i=0; i<m; i++) {
    int begin, end; cin >> begin >> end;
    ladder[begin][end] = ladder[begin][end+1] = 1;
  }
  dfs(0);

  cout << ans << endl;
  return 0;
}