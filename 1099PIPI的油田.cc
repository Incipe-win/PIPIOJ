#include <bits/stdc++.h>

using namespace std;

char mp[101][101];
int visited[101][101];
int n, m;

void dfs(int x, int y) {
  visited[x][y] = 1;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      int mx = x + i, my = y + j;
      if (mx < 0 || mx >= n || my < 0 || my >= m) {
        continue;
      }
      if (visited[mx][my] == 1 || mp[mx][my] == '*') {
        continue;
      }
      dfs(mx, my);
    }
  }
}

int main() {
  while (~scanf("%d%d", &n, &m)) {
    if (n == 0 && m == 0) {
      break;
    }
    memset(mp, 0, sizeof(mp));
    memset(visited, -1, sizeof(visited));
    getchar();
    for (int i = 0; i < n; ++i) {
      scanf("%s", mp[i]);
      getchar();
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mp[i][j] == '@' && visited[i][j] == -1) {
          dfs(i, j);
          ++res;
        }
      }
    }
    printf("%d\n", res);
  }
  return 0;
}