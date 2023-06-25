/**
题目描述
PIPI定义了一个二维数组：

int maze[5][5] = {
0, 1, 0, 0, 0,
0, 1, 0, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};
它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，请找出从左上角到右下角的最短路线。
输入
仅一组测试用例。
一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
输出
左上角到右下角的最短路径，格式如样例所示。
样例输入
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
样例输出
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
提示
简单轻松的搜索入门~
*/

#include <bits/stdc++.h>

using namespace std;

int mp[5][5];
int dist[5][5];
pair<int, int> path[5][5];

int main() {
  memset(mp, -1, sizeof(mp));
  memset(dist, -1, sizeof(dist));

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      scanf("%d", &mp[i][j]);
    }
  }

  queue<pair<int, int>> que;
  que.push({0, 0});
  dist[0][0] = 0;
  printf("(%d, %d)\n", 0, 0);
  int distance[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!que.empty()) {
    int x = que.front().first, y = que.front().second;
    que.pop();
    for (int j = 0; j < 4; ++j) {
      int mx = x + distance[j][0], my = y + distance[j][1];
      if (mx < 0 || mx >= 5 || my < 0 || my >= 5) {
        continue;
      }
      if (mp[mx][my] == 1 || dist[mx][my] != -1) {
        continue;
      }
      dist[mx][my] = dist[x][y] + 1;
      que.push({mx, my});
      path[mx][my] = {x, y};
    }
  }
  int x = 4, y = 4;
  stack<pair<int, int>> st;
  while (path[x][y].first != 0 || path[x][y].second != 0) {
    st.push({x, y});
    int x1 = path[x][y].first;
    int y1 = path[x][y].second;
    x = x1;
    y = y1;
  }
  st.push({x, y});
  while (!st.empty()) {
    auto node = st.top();
    st.pop();
    printf("(%d, %d)\n", node.first, node.second);
  }
  return 0;
}