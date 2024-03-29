#include <iostream>
using namespace std;
long long dp[101][11] = {0, };

int main() {
  int n; cin >> n;
  long long answer = 0;

  dp[1][0] = 0;
  for (int i=1; i<10; i++) dp[1][i] = 1;
  
  for (int i=2; i<=n; i++) {
    for (int j=0; j<10; j++) {
      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
    }
  }

  for (int i=0; i<10; i++) {
    answer += dp[n][i];
  }

  cout << answer % 1000000000 << endl;

  return 0;
}