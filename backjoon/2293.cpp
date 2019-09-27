#include <iostream>
using namespace std;
int dp[10001];

int main() {
  int n, k; cin >> n >> k;
  int c[101];
  for (int i=1; i<=n; i++) {
    cin >> c[i];
  }

  dp[0] = 1;

  for (int i=1; i<=n; i++) { 
    for (int j=0; j<=k; j++) {
      if (j-c[i] >= 0) {
        dp[j] = dp[j] + dp[j-c[i]];
      } else {
        dp[j] = dp[j];
      }
    }
  }

  cout << dp[k] << endl;


  return 0;
}