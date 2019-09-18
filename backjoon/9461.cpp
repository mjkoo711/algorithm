#include <iostream>

using namespace std;
long long arr[101];

int main() {
  arr[1] = arr[2] = arr[3] = 1;
  arr[4] = arr[5] = 2;

  for (int i=6; i<=100; i++) arr[i] = arr[i-1] + arr[i-5];

  int testCase; cin >> testCase;
  for (int i=0; i<testCase; i++) {
    int n; cin >> n;
    cout << arr[n] << endl;
  }
  

  return 0;
}