#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;
  int dp[1001][2] = {0, };
  int arr[1001] = {0, };
  int ans = 0; 

  for(int i=1; i<=n; i++) {
    cin >> arr[i];
  }

  for (int i=1; i<=n; i++) {
    int max = 0;
    for (int j=1; j<i; j++) {
      if (arr[j] < arr[i] && max <= dp[j][0]) {
        max = dp[j][0];
        dp[i][0] = max + 1;
      }
    }
  }

  for (int i=n; i>=1; i--) {
    int max = 0;
    for (int j=n; j>i; j--) {
      if (arr[j] < arr[i] && max <= dp[j][1]) {
        max = dp[j][1];
        dp[i][1] = max + 1;
      }
    }
  }

  for (int i=1; i<=n; i++) {
    ans = max(ans, dp[i][0]+dp[i][1]+1);
  }

  cout << ans << endl;

  return 0;
}