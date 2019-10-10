#include <iostream>
#include <vector>
using namespace std;

int arr[21][21];
bool idx[11] = {false, };
int n, ans = 1123456789;
vector<int> teamA, teamB;

int calculateTeam() {
  int sumA = 0, sumB = 0;
  int size = teamA.size();

  for (int i=0; i<size-1; i++) {
    for (int j=i+1; j<size; j++) {
      int memberA1 = teamA[i], memberA2 = teamA[j];
      int memberB1 = teamB[i], memberB2 = teamB[j];
      sumA += (arr[memberA1][memberA2] + arr[memberA2][memberA1]);
      sumB += (arr[memberB1][memberB2] + arr[memberB2][memberB1]);
    }
  }
  return (sumA - sumB) > 0 ? sumA - sumB : sumB - sumA;
}

void combination(int start, int end, int r) {
  if (r == 0) {
    for (int i=1; i<=n; i++) {
      if (idx[i] == true) teamA.push_back(i);
      else teamB.push_back(i);
    }
    ans = min(ans, calculateTeam());
    teamA.clear(); teamB.clear();
    return; 
  }

  for (int i = start; i<=end; i++) {
    idx[i] = true;
    combination(i+1, end, r-1);
    idx[i] = false;
  }
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cin >> arr[i][j];
    }
  }
  
  combination(1, n, n/2);
  cout << ans << endl;
  return 0;
}