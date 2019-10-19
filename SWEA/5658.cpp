#include <iostream>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

map<string, int> m;
int n, k; 

int htoi(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  else if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
  return -1;
}

int htoi(string s) {
  int len = s.size(), sum = 0, idx = 0;
  for (int i=len-1; i>=0; i--) {
    sum += (htoi(s[i]) * pow(16, idx++));
  }
  return sum;
}

string solve(string input) {
  int t=0; 
  while (t < n/4) {
    for (int i=0; i<4; i++) {
      string sub = input.substr(i*(n/4), n/4);
      m[sub] = 1;
    }
    string lastStr = ""; lastStr += input[n-1];
    input.insert(0, lastStr); input.pop_back();
    t++;
  }

  int mapSize = m.size();
  int findIdx = mapSize - k+1, idx = 1;
  for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
    if (idx == findIdx) {
      return iter->first;
    }
    idx++;
  }
  return "";
}

int main() {
  int test; cin >> test;

  for (int t=1; t<=test; t++) {
    cin >> n >> k;
    string input; cin >> input;
    cout << "#" << t << " " << htoi(solve(input)) << endl;
    m.clear();
  }
  return 0;
}