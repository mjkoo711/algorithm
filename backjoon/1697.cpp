#include <iostream>
#include <queue>
using namespace std;
bool visited[100001] = {false, };

int main() {
  int subin, brother; cin >> subin >> brother;
  int cnt = 0;
  queue<pair<int, int> > q;

  q.push(make_pair(subin, cnt));
  visited[subin] = true;

  while(!q.empty()) {
    pair<int, int> current = q.front(); q.pop();
    if (current.first == brother) { 
      cout << current.second << endl;
      break;
    }
    
    if (current.first-1 >= 0 && visited[current.first-1] == false) {
      q.push(make_pair(current.first-1, current.second+1));
      visited[current.first-1] = true;
    }
    if (current.first+1 <= 100000 && visited[current.first+1] == false) {
      q.push(make_pair(current.first+1, current.second+1));
      visited[current.first+1] = true;
    }
    if (current.first*2 <= 100000 && visited[current.first*2] == false) {
      q.push(make_pair(current.first*2, current.second+1));
      visited[current.first*2] = true;
    }
  }
  return 0;
}