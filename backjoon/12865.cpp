#include <iostream>
#include <vector>
using namespace std;
int dp[101][100001] = {0, };

struct Item {
  int weight, value;
  Item() {}
  Item(int weight, int value): weight(weight), value(value) {}
};

int main() {
  Item items[101];
  int n, k; cin >> n >> k;
  for (int i=1; i<=n; i++) {
    int w, v; cin >> w >> v;
    items[i] = Item(w, v);
  }

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=k; j++) {
      dp[i][j] = dp[i-1][j]; // i번째 물건을 안 실을때
      if (j - items[i].weight >= 0) {// i번째 물건을 실을 수 있을 때 
        dp[i][j] = max(dp[i][j], dp[i-1][j-items[i].weight] + items[i].value);
      }
    }
  }

  cout << dp[n][k] << endl;

  return 0;
}