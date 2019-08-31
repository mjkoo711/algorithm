#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void showDFSPath(vector<int> vec[], int vertex, int edge, int startVertex);
void showBFSPath(vector<int> vec[], int vertex, int edge, int startVertex);

int main() {
  int vertex, edge, startVertex; 
  int temp1, temp2;

  cin >> vertex >> edge >> startVertex;

  vector<int> vertexVector[vertex+1];
  
  for (int i=0 ; i<edge ; i++) {
    int vertex1, vertex2;
    cin >> vertex1 >> vertex2;

    vertexVector[vertex1].push_back(vertex2);
    vertexVector[vertex2].push_back(vertex1);
  }

  for (int i=1 ; i<=vertex ; i++) {
    sort(vertexVector[i].begin(), vertexVector[i].end());
  }

  showDFSPath(vertexVector, vertex, edge, startVertex);
  showBFSPath(vertexVector, vertex, edge, startVertex);

  return 0;
}

void showDFSPath(vector<int> vec[], int vertex, int edge, int startVertex) {
  stack<int> s;
  bool visited[vertex+1];
  for (int i=1 ; i<=vertex ; i++) { visited[i] = false; }

  s.push(startVertex);

  while (!s.empty()) {
    int newStartVertex = s.top(); s.pop();
    if (visited[newStartVertex] == true) { continue; }

    cout << newStartVertex << " ";
    visited[newStartVertex] = true;

    for (int i=vec[newStartVertex].size()-1; i>=0; i--) {
      s.push(vec[newStartVertex][i]);
    }
  }

  cout << endl;
}

void showBFSPath(vector<int> vec[], int vertex, int edge, int startVertex) {
  queue<int> q;
  bool visited[vertex+1];
  for (int i=1 ; i<=vertex ; i++) { visited[i] = false; }

  q.push(startVertex);

  while (!q.empty()) {
    int newStartVertex = q.front(); q.pop(); 
    if (visited[newStartVertex] == true) { continue; }
    
    cout << newStartVertex << " ";
    visited[newStartVertex] = true;

    for (int i=0 ; i < vec[newStartVertex].size(); i++) {
      q.push(vec[newStartVertex][i]);
    }
  }

  cout << endl;
}