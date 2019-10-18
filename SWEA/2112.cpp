#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define A 0
#define B 1
using namespace std;
int film[14][21], copyFilm[14][21];
int r, c, k; 

bool check() {
  int total = 0;
  for (int j=0; j<c; j++) {
    int cnt = 1;
    for (int i=0; i<r-1; i++) {
      if (film[i][j] != film[i+1][j]) {
        if (i+k >= r) return false;
        cnt = 1; continue;
      }
      cnt++;
      if (cnt >= k) { total++; break; }
    }
  }
  if (total != c) return false;
  return true;
}

void change(int idx, int value) {
  for (int j=0; j<c; j++) {
    film[idx][j] = value;
  }
}

int test(vector<int> vec) {
  vector<int> checkRow;
  int cnt = 0;
  for (int i=0; i<r; i++) {
    if (vec[i] == 0) { checkRow.push_back(i); cnt++; }
  }

  for (int i=0; i < (1 << cnt); i++) {
    int tmpCnt = 0;
    int val = i;
    memcpy(copyFilm, film, sizeof(film));
    while (tmpCnt < cnt) {
      change(checkRow[tmpCnt++], val % 2);
      val = val / 2;
    }
    if (check()) return cnt;
    memcpy(film, copyFilm, sizeof(film));
  }
  return -1;
}

int solve() {
  if (k==1) return 0;
  int insert;
  for (insert=0; insert<k; insert++) { // k이상의 답은 없음
    if (insert == 0) {
      if (check()) return 0;
      else continue;
    }
    
    vector<int> permute(r, 1);
    for (int i=0; i<insert; i++) permute[i] = 0;
    do {
      if(test(permute) >= 0) {
        return insert;
      }
    } while (next_permutation(permute.begin(), permute.end()));
  }

  return k;  
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t, test = 1; cin >> t;

  while (test <= t) {
    cin >> r >> c >> k;
    for (int i=0; i<r; i++)
      for (int j=0; j<c; j++) 
        cin >> film[i][j];

    cout << '#' << test++ << ' ' << solve() << "\n";
    memset(film, 0, sizeof(film));
  }
  return 0;
}