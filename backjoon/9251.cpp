#include <iostream>
using namespace std;
int dp[1001][1001] = {0, };

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string str1, str2;
  int length1, length2;
  cin >> str1 >> str2;
  length1 = str1.length();
  length2 = str2.length();

  for (int i=1; i<=length2; i++) {
    for (int j=1; j<=length1; j++) {
      if (str2[i-1] != str1[j-1]) {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      } else {
        dp[i][j] = dp[i-1][j-1] + 1;
      }
    }
  }

  cout << dp[length2][length1] << endl;
  return 0;
}