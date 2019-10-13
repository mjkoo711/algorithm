#include <iostream>
#include <vector>
#define UP 0
#define RIGHT 1
#define DOWN 2 
#define LEFT 3

using namespace std;
int row, col;
char office[9][9];
int ans = 1123456789;

struct CCTV {
  int x, y;
  char num;
  CCTV(int x, int y, char num): x(x), y(y), num(num) {}
};
vector<CCTV> ccties;

void solve(int cctvIdx);
void checkArea(CCTV cctv, int dir) {
  int x = cctv.x, y = cctv.y;

  if (dir == LEFT) {
    for (int i=y-1; i>=0; i--) {
      if (office[x][i] == '6') break;
      if (office[x][i] == '0') {
        office[x][i] = '#';
      }
    }
  } 

  if (dir == RIGHT) {
    for (int i=y+1; i<col; i++) {
      if (office[x][i] == '6') break;
      if (office[x][i] == '0') {
        office[x][i] = '#';
      }
    }
  }

  if (dir == UP) {
    for (int i=x-1; i>=0; i--) {
      if (office[i][y] == '6') break;
      if (office[i][y] == '0') {
        office[i][y] = '#';
      }
    }
  }

  if (dir == DOWN) {
    for (int i=x+1; i<row; i++) {
      if (office[i][y] == '6') break;
      if (office[i][y] == '0') {
        office[i][y] = '#';
      }
    }
  }
}

void copyArray(char a[9][9], char b[9][9]) {
  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      a[i][j] = b[i][j];
    }
  }
}

void checkCCTV(CCTV cctv, int cctvIdx) {
  char copyOffice[9][9]; copyArray(copyOffice, office);
  switch(cctv.num) {
  case '1': 
    for (int i=0; i<4; i++) {
      checkArea(cctv, i);
      solve(cctvIdx+1);
      copyArray(office, copyOffice);
    }
    break;
  case '2': 
    for (int i=0; i<2; i++) {
      checkArea(cctv, i);
      checkArea(cctv, i+2);
      solve(cctvIdx+1);
      copyArray(office, copyOffice);
    }
    break;
  case '3': 
    for (int i=0; i<4; i++) {
      checkArea(cctv, i);
      checkArea(cctv, (i+1)%4);
      solve(cctvIdx+1);
      copyArray(office, copyOffice);
    }
    break;
  case '4': 
    for (int i=0; i<4; i++) {
      checkArea(cctv, i);
      checkArea(cctv, (i+1)%4);
      checkArea(cctv, (i+2)%4);
      solve(cctvIdx+1);
      copyArray(office, copyOffice);
    }
    break; 
  case '5': 
    for (int i=0; i<4; i++) checkArea(cctv, i);
    solve(cctvIdx+1);
    copyArray(office, copyOffice);
    break;
  }
}

void solve(int cctvIdx) {
  if (cctvIdx == ccties.size()) {
    int cnt = 0;
    for (int i=0; i<row; i++) {
      for (int j=0; j<col; j++) {
        if (office[i][j] == '0') cnt++;
      }
    }
    ans = min(cnt, ans);
    return;
  }

  checkCCTV(ccties[cctvIdx], cctvIdx);
}

int main() {
  cin >> row >> col;

  for (int i=0; i<row; i++) {
    for (int j=0; j<col; j++) {
      cin >> office[i][j];
      if (office[i][j] >= '1' && office[i][j] <= '5') {
        ccties.push_back(CCTV(i, j, office[i][j]));
      }
    }
  }
  solve(0);

  cout << ans << endl;
  return 0;
}