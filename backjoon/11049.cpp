#include <iostream>
#include <climits>
#include <vector>
using namespace std;
struct Matrix {
  int x, y;
  Matrix() {}
  Matrix(int x, int y): x(x), y(y) {}
};

int main() {
  int n; cin >> n;
  int dp[n][n];

  ios::sync_with_stdio(false);
  cin.tie(0);

  Matrix matrix[n];
  
  for (int i=0; i<n; i++) {
    int a, b; cin >> a >> b;
    matrix[i] = Matrix(a, b);
  }
  

  for (int i=0; i<n; i++) {
    dp[i][i] = 0;
    dp[i][i+1] = matrix[i].x * matrix[i].y * matrix[i+1].y;
  }

  for (int gap=2; gap<n; gap++) {
    for (int i=0; i<n-gap; i++) {
      int minimum = INT_MAX;
      for (int k=i; k<i+gap; k++) {
        minimum = min(minimum, dp[i][k] + dp[k+1][i+gap] + (matrix[i].x * matrix[k].y * matrix[i+gap].y));
      }
      dp[i][i+gap] = minimum;
    }
  }

  cout << dp[0][n-1] << endl;
  return 0;
}