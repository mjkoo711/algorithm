#include <iostream>
using namespace std;

int findMax(int a, int b) {
  return (a > b) ? a : b;
}

int main() {
  ios::sync_with_stdio(0);
	cin.tie(0);
  int n; cin >> n;
  int arr[501][501] = {-1, };
  int dp[501][501] = {0, };
  int answer = 0;
  int top; cin >> top;
  dp[0][0] = arr[0][0] = top;


  for (int i=1; i<n; i++) {
    for (int j=0; j<=i; j++) {
      int temp; cin >> temp;
      arr[i][j] = temp;
      if (arr[i-1][j] == -1 || (i-1 < 0)) dp[i][j] = arr[i][j] + dp[i-1][j-1];
      else if (arr[i-1][j-1] == -1 || (i-1 < 0) || (j-1) < 0) dp[i][j] = arr[i][j] + dp[i-1][j];
      else {
        dp[i][j] = arr[i][j] + findMax(dp[i-1][j], dp[i-1][j-1]);
      }
    }
  }

  answer = dp[n-1][0];
  for (int i=1; i<n; i++) {
    if (answer < dp[n-1][i]) answer = dp[n-1][i];
  }

  cout << answer << endl;
  return 0;
}