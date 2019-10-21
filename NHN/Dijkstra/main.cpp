#include <iostream>
#include <vector>
#include <queue>
#define INF 123456789

using namespace std;

int main() {
  int V, E; // V : 노드 개수, E : 엣지 개수
  cin >> V >> E; 
  int start; cin >> start; // 시작점 입력
  vector<pair<int, int> > arr[V+1];

  for (int i=0; i<E; i++) {
    int from, to, val; cin >> from >> to >> val;
    arr[from].push_back({to, val});
  }

  int dist[V+1]; // 최단 거리를 갱신해주는 배열 
  fill(dist, dist+V+1, INF); // 무한대로 전부 초기화
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> pq;
  pq.push({0, start}); // 우선순위 큐에 시작점을 넣어준다
  dist[start] = 0;

  while(!pq.empty()) {
    int cost = pq.top().first; // 다음 방문할 점의 dist 값
    int here = pq.top().second; // 방문할 점의 번호

    pq.pop();

    for (int i=0; i<arr[here].size(); i++) {
      int next = arr[here][i].first; 
      int nextCost = arr[here][i].second;

      if (dist[next] > dist[here] + nextCost) {
        dist[next] = dist[here] + nextCost;
        pq.push({dist[next], next});
      }
    }
  }
}