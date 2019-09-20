#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  vector<int> vec;
  int max;

  for (int i=0; i<n; i++) {
    int temp; cin >> temp;
    vec.push_back(temp);
  }

  sort(vec.begin(), vec.end());
  max = vec[n-1];

  for (int k=2; k<=n; k++) {
    if (max < vec[n-k] * k) {
      max = vec[n-k] * k;
    }
  }

  cout << max << endl;

  return 0;
}