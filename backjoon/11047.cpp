#include <queue>
#include <iostream>
#include <vector>

void question11047(int n, int k, std::vector<int> vec);

int main() {
  int n, k; 
  int temp; 

  std::vector<int> vector;

  std::cin >> n;
  std::cin >> k;

  for (int i = 0; i < n; i++) {
    std::cin >> temp; 
    vector.push_back(temp);
  }

  question11047(n, k, vector);
  return 0;
}

void question11047(int n, int k, std::vector<int> vec) {
  int count = 0;

  for (int i = n-1; i >= 0; i--) {
    count += (k/vec[i]);
    k = k % vec[i];
  }

  std::cout << count << std::endl;
}