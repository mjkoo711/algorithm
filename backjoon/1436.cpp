#include <iostream>
#include <vector>

using namespace std;
bool check(int a) {
  int count = 0;
  while (a > 0) {
    if (a%10 == 6) {
      count++;
    } else { count = 0;}
    a = a/10;
    if (count == 3) return true;
  }
  return false;
}

int main() {
  int n; cin >> n;
  int cnt = 1;

  vector<long long> vec;
  vec.push_back(666);
  for (int i=667; i<100000000; i++) {
    if(check(i)) {
      cnt++;
      vec.push_back(i);
    }
    if (cnt == n) {
      cout <<vec[n-1] << endl;
      break;
    }
  }
  return 0;
}