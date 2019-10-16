#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 987654321

int n, m, ans = INF;
int storeSize = 0, houseSize = 0;
vector<pair<int, int> > houses, stores;

int dist(pair<int, int> a, pair<int, int> b) {
  return abs(a.first-b.first) + abs(a.second-b.second);
}

int main() {
  scanf("%d %d", &n, &m);

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      int tmp; scanf("%d", &tmp);
      if (tmp == 1) houses.push_back(make_pair(i, j));
      else if (tmp == 2) stores.push_back(make_pair(i, j));
    }
  }
  storeSize = stores.size(); houseSize = houses.size();

  vector<int> open(storeSize, 1);
  for (int i=0; i<m; i++) open[i] = 0;

  do {
    int sum = 0;
    for (int i=0; i<houseSize; i++) {
      int dis = INF;
      for (int j=0; j<storeSize; j++) 
        if (open[j] == 0) dis = min(dis, dist(houses[i], stores[j]));
      sum += dis;
    }
    ans = min(ans, sum);
  } while(next_permutation(open.begin(), open.end()));

  printf("%d", ans);
  return 0;
}