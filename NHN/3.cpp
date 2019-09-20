#include <iostream>
#include <vector>
using namespace std;

int main() {
  int days; cin >> days;
  int prices[10001] = {10001, };
  int gain = 0;
  int max = 0;
  int coin = 0;

  int buy = 0;

  for (int i=1; i<=days; i++) {
    cin >> prices[i];
  }

  for (int i=days; i>0; i--) {
    if (max < prices[i]) {
      max = prices[i];
      buy = 0;
      coin = 0;
    } else {
      buy += prices[i];
      coin++;

      cout << "buy : " << buy << endl;
      if (prices[i-1] > prices[i]) {
        gain += (((max*coin) - buy));
        gain -= 1;
        cout <<"prices : " << prices[i]  << "coin : " << coin << "gain : " << gain << endl;


      }

      
    }
  }


  cout << gain << endl;

  return 0;
}