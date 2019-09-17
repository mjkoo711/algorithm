#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
  int weight;
  int tall;
  int rank;

  Person(int weight, int tall) {
    this->weight = weight;
    this->tall = tall;
    rank = 1;
  }
};

int main() {
  int n;
  cin >> n;

  vector<Person> people;

  for (int i=0; i<n; i++) {
    int weight, tall;
    cin >> weight >> tall;

    people.push_back(Person(weight, tall));
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (i==j) continue;
      else if (people[i].weight < people[j].weight && people[i].tall < people[j].tall) {
        people[i].rank++;
      }
    }
  }

  for (int i=0; i<n; i++) 
    cout << people[i].rank << " ";
  cout << endl;  
  return 0;
}