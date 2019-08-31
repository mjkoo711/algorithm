#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int cardCount, target;
  vector<int> vec;
  int temp;
  int sum = 0;

  cin >> cardCount >> target;
  
  for (int i = 0; i < cardCount; i++) {
    cin >> temp;
    vec.push_back(temp);
  }

  sort(vec.begin(), vec.end());
  
  for (int i=0; i< cardCount-2; i++) {
    for (int j=i+1; j < cardCount-1; j++) {
      for (int k=j+1; k < cardCount; k++) {
        if (vec[i] + vec[j] + vec[k] <= target && target - (vec[i] + vec[j] + vec[k]) < target - sum) {
          sum = vec[i] + vec[j] + vec[k];
        }
      }
    }
  }

  cout << sum << endl;

  return 0;
}