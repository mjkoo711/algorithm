#include <iostream>
using namespace std;
int findMax(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n; cin >> n;
  int dp[301] = {0, };
  int score[301] = {0, };

  int first; cin >> first;  dp[0] = score[0] = first;
  int second; cin >> second; score[1] = second; 
  int third; cin >> third; score[2] = third;
  dp[1] = score[0] + score[1];
  dp[2] = findMax(score[0] + score[2], score[1] + score[2]);

  for (int i=3; i<n; i++) {
    int temp; cin >> temp;
    score[i] = temp;
    dp[i] = findMax(dp[i-2], dp[i-3] + score[i-1]) + score[i];
  }

  cout << dp[n-1] << endl;
  return 0;
}