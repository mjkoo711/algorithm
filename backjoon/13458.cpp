#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, b, c; cin >> n;
  vector<int> vec(n);
  long long ans = (long long) n;

  for (int i=0; i<n; i++) cin >> vec[i];
  cin >> b >> c;
  
  for (int i=0; i<n; i++) {
    vec[i] -= b;
    if (vec[i] <= 0) continue;
    ans += (vec[i] / c); 
    if (vec[i] % c > 0) ans++;
  }

  cout << ans << endl;

  return 0;
}