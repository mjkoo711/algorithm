#include <iostream>
using namespace std;
int arr[1000001] = {0, };

int findMin(int a, int b) {
  return a < b ? a : b;
}

int main() {
  int input; cin >> input;
  arr[1] = 0;
  arr[2] = arr[3] = 1;

  for (int i=4; i<=input; i++) {
    if (i%6 == 0) {
      arr[i] = findMin(findMin(arr[i/3], arr[i/2]), arr[i-1]) + 1;
    } else if (i%3 == 0) { 
      arr[i] = findMin(arr[i/3], arr[i-1]) + 1;
    } else if (i%2 == 0) {
      arr[i] = findMin(arr[i/2], arr[i-1]) + 1;
    } else {
      arr[i] = arr[i-1] + 1;
    }
  }

  cout << arr[input] << endl;
  return 0;
}