#include <iostream>
#include <vector>
using namespace std;

int add(string s) {
  int sum = 0;
  string op1 = "";

  for (int i=0; i<s.length(); i++) {
    if (s[i] == '+') {
      sum += atoi(op1.c_str());
      op1 = "";
    } else {
      op1 += s[i];
    }
  }
  sum += atoi(op1.c_str());
  return sum;
}

int main() {
  string s; cin >> s;
  vector<string> exps;
  string temp = "";

  for (int i=0; i<s.length(); i++) {
    if (s[i] == '-') {
      exps.push_back(temp);
      temp = "";
    } else {
      temp += s[i];
    }
    int s; cin >> s;
    int dp[s];
  }
  exps.push_back(temp);

  int answer = add(exps[0]); exps.erase(exps.begin());

  for (int i=0; i<exps.size(); i++) {
    answer -= add(exps[i]);
  } 

  cout << answer << endl;

  return 0;
}