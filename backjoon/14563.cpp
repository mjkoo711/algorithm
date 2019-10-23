#include <iostream>
using namespace std;

string perfect(int num) {
  if (num == 1) return "Deficient";
  int sum = 1;

  for (int i=2; i<=num/2; i++) {
    if (num % i == 0) {
      sum += i;
    }
  }
  if (sum == num) return "Perfect";
  else if (sum < num) return "Deficient";
  else return "Abundant";
}

int main() {
  int n; cin >> n;
  while (n--) {
    int num; cin >> num;
    cout << perfect(num) << endl;
  }
  return 0;
}