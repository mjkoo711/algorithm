#include <iostream>
#include <vector>
using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

struct Info {
  char c;
  int x;
  Info(char c, int x): c(c), x(x) {}
};

struct Point {
  int r, c;
  Point(int r, int c): r(r), c(c) {};
};

int n, appleCount, turnCount, dir = 0, ans = 1;
vector<Info> turnInfo;
vector<Point> snake;

int map[101][101] = {{0, }, };
bool check[101][101] = {{false, }, };

int main() {
  cin >> n >> appleCount;
  check[1][1] = true;
  snake.push_back(Point(1, 1));

  for (int i=0; i<appleCount; i++) {
    int x, y; cin >> x >> y;
    map[x][y] = 1; // 사과 존재
  }

  cin >> turnCount;
  for (int i=0; i<turnCount; i++) {
    char c; int x; cin >> x >> c;
    turnInfo.push_back(Info(c, x));
  }

  for (int second=1 ;; second++) {
    int head_r = snake[snake.size()-1].r, head_c = snake[snake.size()-1].c;
    int next_r = head_r + dr[dir], next_c = head_c + dc[dir];

    if (check[next_r][next_c] == true || next_r < 1 || next_r > n || next_c < 1 || next_c > n) {
      cout << ans << endl;
      return 0;
    }

    if (map[next_r][next_c] == 1) {
      map[next_r][next_c] = 0;
      check[next_r][next_c] = true; snake.push_back(Point(next_r, next_c));
      ans++;
    } else if (map[next_r][next_c] == 0) {
      int tail_r = snake[0].r, tail_c = snake[0].c; 
      check[tail_r][tail_c] = false; snake.erase(snake.begin());
      check[next_r][next_c] = true; snake.push_back(Point(next_r, next_c));
      ans++;
    }

    for (int i=0; i<turnCount; i++) {
      if (turnInfo[i].x == second) {
        if (turnInfo[i].c == 'D') {
          dir = dir+1 > 3 ? 0 : dir+1;
        } else if (turnInfo[i].c == 'L') {
          dir = dir-1 < 0 ? 3 : dir-1;
        }
      }
    }
  }
  return 0;
}