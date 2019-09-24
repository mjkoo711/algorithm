#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n; cin >> n;
  vector<pair<int, int> > lines;
  vector<int> LIS;

  int ans = 0;
  
  for (int i=0; i<n; i++) {
    int a, b; cin >> a >> b;
    lines.push_back(make_pair(a, b));
  }
  sort(lines.begin(), lines.end());

  for (int i=0; i<n; i++) {
    if (LIS.size() == 0) {
      LIS.push_back(lines[i].second);
      continue;
    }
    if (LIS.back() < lines[i].second) {
      LIS.push_back(lines[i].second);
    } else {
      for (int j=0; j<LIS.size(); j++) {
        if (LIS[j] > lines[i].second) {
          LIS[j] = lines[i].second;
          break;
        }
      }
    }
  }

  cout << n-LIS.size() << endl;
  return 0;
}