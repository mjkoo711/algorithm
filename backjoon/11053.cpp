#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int arr[1001] = {0, };
  int dp[1001] = {0, };
  int ans = 0;

  int n; cin >> n;
  for (int i=1;i <= n; i++) {
    cin >> arr[i];
  }

  for (int i=1; i<=n; i++) {
    int here = 0;
    for (int j=1; j<i; j++) {
      if (arr[i] > arr[j]) {
        here = max(here, dp[j]);
      }
    }
    dp[i] = here + 1;
    ans = max(dp[i], ans);
  }

  cout << ans << endl;
  
  return 0;
}