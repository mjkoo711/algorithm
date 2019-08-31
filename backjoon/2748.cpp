#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void fibo(int number);

int main() {
  int number;
  cin >> number;
  fibo(number);
  
  return 0;
}

void fibo(int number) {
  vector<long long> fiboArray(91);
  fiboArray[0] = 0;
  fiboArray[1] = 1;

  for (int i=2; i<=number; i++) {
    fiboArray[i] = fiboArray[i-1] + fiboArray[i-2];
  }

  cout << fiboArray[number] << endl;
}