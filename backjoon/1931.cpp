#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<uint ,uint> v1, pair<uint, uint> v2) {
  if (v1.second != v2.second) {
    return v1.second < v2.second;
  } else {
    return v1.first < v2.first;
  }
}

int main() {
  int conferences;
  int maxConferences = 1 ;

  cin >> conferences;
  vector<pair<uint ,uint> > vec;

  uint start, end;
  for (int i=0; i<conferences; i++) {
    cin >> start >> end;
    vec.push_back(make_pair(start, end));
  }

  sort(vec.begin(), vec.end(), compare);

  int finish = vec[0].second;
 
  for (int i=1; i<conferences; i++) {
    if (vec[i].first >= finish) {
      finish = vec[i].second;
      maxConferences++;
    }
  }

  cout << maxConferences << endl;
  return 0;
}