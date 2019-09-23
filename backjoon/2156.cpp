#include <iostream>
#include <vector>

using namespace std;
int findMax(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int graphs[10001];
  
  int dp[10001] = {0, };
  int cnt; cin >> cnt;
  for (int i=1; i<=cnt; i++) {
    cin >> graphs[i];
  }

  dp[0] = 0;
  dp[1] = graphs[1];
  dp[2] = dp[1] + graphs[2];

  for (int i=3; i<=cnt; i++) {
    dp[i] = findMax(dp[i-1], findMax(dp[i-2] + graphs[i], dp[i-3] + graphs[i-1] + graphs[i]));
  }

  cout << dp[cnt] << endl;

  return 0;
}