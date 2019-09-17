#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  long long sum = 0;
  vector<int> p;
  vector<int> a;

  cin >> n;

  for (int i=0; i<n; i++) {
    int temp;
    cin >> temp;
    p.push_back(temp);
  }

  sort(p.begin(), p.end());
  
  a.push_back(p[0]);

  for (int i=1; i<n; i++) {
    a.push_back(a[i-1] + p[i]);
  }

  for (int i=0; i<n; i++) {
    sum += a[i];
  }
  cout << sum << endl;
  return 0;
}