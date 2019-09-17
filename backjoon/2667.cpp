#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[26][26] = {false, };
char arr[26][26] = {'0', };

int BFS(int n, int i, int j, queue<pair<int, int> > q) {
  int count = 1;
  while (!q.empty()) {
    pair<int, int> p = q.front(); q.pop();

    for (int a=-1; a<=1; a++) {
      for (int b=-1; b<=1; b++) {
        if ((a==b) || (a+b == 0) || p.first+a < 0 || p.second+b < 0 || p.first+a >= n || p.second+b >= n) continue;

        if (arr[p.first+a][p.second+b] == '1' && visited[p.first+a][p.second+b] == false) {
          visited[p.first+a][p.second+b] = true;
          count++;
          q.push(make_pair(p.first+a, p.second+b));
        }
      }
    }
  }

  return count;
}

int main() {
  int n;
  int count = 0;

  queue<pair<int, int> > q;
  vector<int> answer;
  cin >> n;

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      cin >> arr[i][j];

  for (int i=0; i<n; i++) {  
    for (int j=0; j<n; j++) { 
      if (arr[i][j] == '1' && visited[i][j] == false) {
        q.push(make_pair(i, j));
        visited[i][j] = true;
        answer.push_back(BFS(n, i, j, q));
        count++;
      }
    }
  }

  cout << count << endl;
  sort(answer.begin(), answer.end());
  for (int i=0; i<count; i++) {
    cout << answer[i] << endl;
  }

  return 0;
}