#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> cards;


void shuffle(int n, int cardCount) {
  int currentCount = cardCount;
  queue<int> q;


  while (currentCount > 2*n) {
    for (int i=0; i<currentCount-n; i++) {
      q.push(cards[i]);
    }

    for(int i=0; i<n; i++) {
      int front = q.front(); q.pop();
      q.push(front);
    }

    for(int i=0; i<currentCount-n; i++) {
      cards[i] = q.front(); q.pop();
    }

    currentCount = currentCount - 2*n;
  }
}

int main() {

  int cardCount; cin >> cardCount;
  int playCount; cin >> playCount;

  for (int i=1; i<=cardCount; i++) 
    cards.push_back(i);

  for (int i=0; i<playCount; i++) {
    int n; cin >> n;
    shuffle(n, cardCount);
  }

  for (int i=0; i<5; i++) 
    cout << cards[i] << endl;
  return 0;
}