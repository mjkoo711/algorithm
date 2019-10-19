#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int map[100][100];
int n, l, ans = 0;

bool check(vector<int> vec) {
  int size = vec.size();
  bool visited[100] = {false, };

  for (int i=0; i<size-1;) {
    if (abs(vec[i] - vec[i+1]) > 1) return false;
    if (vec[i] - vec[i+1] == 1) {
      int start = i+1, cnt = 1;
      while (cnt < l) {
        if (vec[start] != vec[start+1]) return false;
        cnt++; start++;
      }
      
      if (cnt == l) {
        for (int k = i+1; k < i+1+l; k++) {
          if (visited[k] == true) return false;
          visited[k] = true;
        }
        i = i+l;
        continue;
      }
    } else if (vec[i] - vec[i+1] == -1) {
      int end = i, cnt = 1;
      while (cnt < l) {
        if (vec[end] != vec[end-1]) return false;
        cnt++; end--;
      }

      if (cnt == l) {
        for (int k=i; k>i-l; k--) {
          
          if (visited[k] == true) return false;
          visited[k] = true;
        }
      }
    }
    i++;
  }
  return true;
}

int main() {
  cin >> n >> l;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> map[i][j];
    }
  }
  // 가로로 
  for (int i=0; i<n; i++) {
    vector<int> vec;
    for (int j=0; j<n; j++) 
      vec.push_back(map[i][j]);
    if (check(vec)) ans++;
  }

  // 세로로 
  for (int j=0; j<n; j++) {
    vector<int> vec;
    for (int i=0; i<n; i++) 
      vec.push_back(map[i][j]);
    if (check(vec)) ans++;
  }

  cout << ans << endl;

  return 0;
}