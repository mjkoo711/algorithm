#include <iostream>
#include <vector>
using namespace std;

bool dp[2001][2001];

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> vec(n+1, 0);

  for (int i=1; i<=n; i++) cin >> vec[i];

  for (int i=1; i<=n; i++) {
    dp[i][i] = true;
    if (i+1 <= n && vec[i] == vec[i+1]) dp[i][i+1] = true;
  }

  for (int diff=2; diff<=n-1; diff++) {
    for (int i=1; i<=n-diff; i++) {
      if (vec[i] == vec[i+diff] && dp[i+1][i+diff-1]) dp[i][i+diff] = true;
      else dp[i][i+diff] = false;
    }
  }

  int m; cin >> m;
  while (m--) {
    int s, e; cin >> s >> e;
    cout << dp[s][e] << '\n';
  }
  return 0;
}