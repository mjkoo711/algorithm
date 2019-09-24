#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;
  long long arr[n];
  long long dp[n];
  long long ans;

  for (int i=0; i<n; i++) cin >> arr[i];
  for (int i=n-1; i>=0; i--) {
    if (i==n-1) {
      dp[i] = arr[n-1];
      ans = dp[i];
    }
    else {
      dp[i] = max(arr[i], dp[i+1] + arr[i]);
      ans = max(dp[i], ans);
    }
  }

  cout << ans << endl;

  return 0;
}