#include <iostream>
#include <queue>

using namespace std;

int arr[52][52] = {0, };
bool visited[52][52] = {false, };

int rowIdx[4] = {-1, 1, 0, 0};
int colIdx[4] = {0, 0, 1, -1};

void initial() {
  for (int i=0; i<52; i++) {
    for (int j=0; j<52; j++) {
      arr[i][j] = 0;
      visited[i][j] = false;
    }
  }
}

void DFS(int i, int j, int row, int col) {
  visited[i][j] = true;

  for (int x=0; x<4; x++) {
    if (i+rowIdx[x] < 0 || i+rowIdx[x] >= row || j+colIdx[x] < 0 || j+colIdx[x] >= col) continue;
    if (arr[i+rowIdx[x]][j+colIdx[x]] == 1 && visited[i+rowIdx[x]][j+colIdx[x]] == false) {
      DFS(i+rowIdx[x], j+colIdx[x], row, col);
    } else { continue; }
  }
  
}

int main() {
  int testCase;
  int row, col, cabbage;

  cin >> testCase;

  for (int test=0; test<testCase; test++) {
    int count = 0;
    initial();
    cin >> col >> row >> cabbage;

    while(cabbage-- > 0) {
      int x, y;
      cin >> x >> y;
      arr[y][x] = 1;
    }

    for (int i=0; i<row; i++) {
      for (int j=0; j<col; j++) {
        if (arr[i][j] == 1 && visited[i][j] == false) {
          DFS(i, j, row, col);
          count++;
        }
      }
    }

    cout << count << endl;
  }


  return 0;
}