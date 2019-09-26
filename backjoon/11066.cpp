#include <iostream>
#include <climits>
using namespace std;


int main() {
  int T; cin >> T;
  for (int t=0; t<T; t++) {
    int N; cin >> N;
    int arr[N];
    int dp[N][N];
    int sum[501] = {0, };

    for (int i=0; i<N; i++) {
      cin >> arr[i];
      dp[i][i] = 0;
      sum[i] = sum[i-1] + arr[i];
    }

    for (int gap=1; gap<=N-1; gap++) {
      for (int dx=0; dx<N-gap; dx++) {
        int minimum = INT_MAX;
        for (int mid=dx; mid<dx+gap; mid++) {
          int dy = dx + gap;
          minimum = min(minimum, dp[dx][mid] + dp[mid+1][dy]);
        }
        dp[dx][dx+gap] = minimum + sum[dx+gap] - sum[dx-1];
      }
    }

    cout << dp[0][N-1] << endl;
  }
  return 0;
}