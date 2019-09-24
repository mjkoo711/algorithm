#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n; cin >> n;
  int T[16] = {0, };
  int P[16] = {0, };
  int dp[16] = {0, };
  int ans = 0;
  for (int i=1; i<=n; i++) {
    cin >> T[i] >> P[i];
  }

  for (int i=n; i>=1; i--) {
    if (i + T[i] > n + 1) dp[i] = 0;
    else {
      int tmp = 0;
      for (int j=i + T[i]; j<=n; j++) {
        tmp = max(tmp, dp[j]);
      }
      dp[i] = P[i] + tmp;
    }
  }

  for (int i=1; i<=n; i++) {
    ans = max(ans, dp[i]);
  }

  cout << ans << endl;

  return 0;
}