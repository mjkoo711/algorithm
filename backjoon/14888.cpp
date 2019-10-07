#include <iostream>
#include <algorithm>
#include <vector>
#define PLUS 1
#define MINUS 2
#define MULTI 3
#define DIVIDE 4

using namespace std;

int main() {
  int n; cin >> n;
  ios::sync_with_stdio(false); cin.tie(0);
  long long minAns = 1000000001, maxAns = -1000000001;
  vector<int> operands;
  vector<int> operators;

  for (int i=0; i<n; i++) {
    int tmp; cin >> tmp; 
    operands.push_back(tmp);
  }

  for (int i=0; i<4; i++) {
    int tmp; cin >> tmp;
    if (i==0) {
      for (int j=0; j<tmp; j++) operators.push_back(PLUS);
    } else if (i==1) {
      for (int j=0; j<tmp; j++) operators.push_back(MINUS);
    } else if (i==2) {
      for (int j=0; j<tmp; j++) operators.push_back(MULTI);
    } else {
      for (int j=0; j<tmp; j++) operators.push_back(DIVIDE);
    }
  }

  do {
    vector<int> permutation;
    int idx = 0;
    long long result = operands[idx];

    for (int i=0; i<operators.size(); i++) {
      permutation.push_back(operators[i]);
    }

    for (int i=0; i<permutation.size(); i++) {
      if (permutation[i] == PLUS) {
        result += operands[++idx];
      } else if (permutation[i] == MINUS) {
        result -= operands[++idx];
      } else if (permutation[i] == MULTI) {
        result *= operands[++idx];
      } else if (permutation[i] == DIVIDE){
        result /= operands[++idx];
      }
    }

    minAns = min(minAns, result);
    maxAns = max(maxAns, result);
  } while(next_permutation(operators.begin(), operators.end()));
  
  cout << maxAns << "\n" << minAns << endl;
  return 0;
}