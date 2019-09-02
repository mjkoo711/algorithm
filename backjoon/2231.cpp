#include <iostream>
using namespace std;

int main() {
  int number;
  cin >> number;

  int original, newNumber;

  for (int i=0; i<number; i++) {
    original = newNumber = i;

    for (int j=0; j<7; j++) {
      newNumber += (original % 10);
      original /= 10;
      if (original == 0 ) break;
    }

    if (number == newNumber) {
      cout << i << endl;
      return 0;
    }
  }

  cout << 0 << endl;

  return 0;
}