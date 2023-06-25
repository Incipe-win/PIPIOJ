/**
题目描述
在一个N*N的棋盘上，问你有多少不同的方式摆放N个皇后。
每个皇后所处的行、列、两条对角线上都不能有其他皇后。
输入
无需处理到EOF
一个整数N,3<=N<=13
输出
输出不同的方案数
样例输入
4
样例输出
2
*/
#include <bits/stdc++.h>

using namespace std;

#define N 15
int col[N], pie[N * N], la[N * N];
int n;
int ans;

void dfs(int row) {
  if (row == n) {
    ++ans;
    return;
  }
  // 思路就是依次访问整个棋盘，第一行的每个位置都尝试是否存在解，如果存在解则+1
  for (int i = 0; i < n; ++i) {
    if (!col[i] && !la[i - row + n] && !pie[i + row]) {
      // 把当前行和主副对角线都打上tag，表明当前行和主副对角线都不能在有皇后了
      col[i] = la[i - row + n] = pie[i + row] = 1;
      dfs(row + 1);
      col[i] = la[i - row + n] = pie[i + row] = 0;
    }
  }
}

int main() {
  while (~scanf("%d", &n)) {
    ans = 0;
    memset(col, 0, sizeof(col));
    memset(pie, 0, sizeof(pie));
    memset(la, 0, sizeof(la));
    dfs(0);
    printf("%d\n", ans);
  }
  return 0;
}