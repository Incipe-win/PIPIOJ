/**
题目描述
PIPI承包了一大片土地，PIPI打了几个油井，发现这片土地的下面有很多地方埋藏着石油，如果一个油井与另一个油井在上，下，左，右，左上，右下，右上，左下这八个方向中的任意一个方向连通，我们就认为这两个油井属于同一个油田。
现在这块土地可以看成是一个n*m的方格矩阵，标记为'@'的方格代表一个油井，标记为'*'的方格代表一块贫瘠的土地。你能告诉PIPI他的这块土地上有几个油田吗?
输入
输入包含多组测试样例。
对于每组测试样例，输入的第一行是两个正整数 n,m (1<=n,m<=100)
接下来输入的一个n*m的方格矩阵，代表PIPI承包土地。
以 0 0结尾结束输入。
输出
对于每组测试样例，输出一行，代表土地上油田的数目。
样例输入
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
样例输出
0
1
2
2
*/
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