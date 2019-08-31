#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void fibo(int number);

int main() {
  int testCase;
  cin >> testCase;

  for (int i=0; i<testCase; i++) {
    int input;
    cin >> input;
    fibo(input);
  }

  return 0;
}

void fibo(int number) {
  vector<pair<int, int> > countVector(41);

  countVector[0] = make_pair(1, 0);
  countVector[1] = make_pair(0, 1);

  for (int i=2 ; i<=number; i++) {
    int countZero = countVector[i-1].first + countVector[i-2].first;
    int countOne = countVector[i-1].second + countVector[i-2].second;
    countVector[i] = make_pair(countZero, countOne);
  }

  cout << countVector[number].first << " " << countVector[number].second << endl;
}