#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, rotation; cin >> n >> rotation;
  string arr[100][100] = {"", };

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> arr[i][j];
    }
  }

  if (rotation < 0) { // 반시계
    rotation *= -1;
  } else { // 시계
    반복 : rotation % ((n-1) * 4) 만큼 
  }
}

// 회전수 양수 : 시계 
// 회전수 음수 : 반시계
// 인접한 두 테두리 회전 방향 : 서로 반대
// 회전수 절댓값 만큼 원소 이둥
/*
2 333
강미나 김도연
김세정 김소혜
*/

// 반시계
[i][j] -> [i][j-1] // 왼쪽
[i][j] -> [i+1][j] // 아래 
[i][j] -> [i][j+1] // 오른쪽 
[i][j] -> [i-1][j] // 위 