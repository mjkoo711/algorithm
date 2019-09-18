#include <iostream>
#include <vector>
using namespace std;

struct House {
  int color[3];
  House(int red, int green, int blue) {
    color[0] = red; color[1] = green; color[2] = blue;
  }
};

long long findMin(long long a, long long b) {
  return (a < b) ? a : b;
}

int main() {
  int count; cin >> count;
  
  vector<House> houses;
  long long distance[count][3];

  for (int i=0; i<count; i++) {
    int red, green, blue;
    cin >> red >> green >> blue; 
    houses.push_back(House(red, green, blue));
  }

  distance[0][0] = houses[0].color[0];
  distance[0][1] = houses[0].color[1];
  distance[0][2] = houses[0].color[2];

  for (int i=1; i<count; i++) {
    distance[i][0] = houses[i].color[0] + findMin(distance[i-1][1], distance[i-1][2]);
    distance[i][1] = houses[i].color[1] + findMin(distance[i-1][0], distance[i-1][2]);
    distance[i][2] = houses[i].color[2] + findMin(distance[i-1][0], distance[i-1][1]);
  }

  cout << findMin(distance[count-1][0], findMin(distance[count-1][1], distance[count-1][2]));

  return 0;
}