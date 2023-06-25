/**
题目描述
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。现得到城镇道路统计表，表中列出了任意两城镇间修建道路的费用，以及该道路是否已经修通的状态。现请你编写程序，计算出全省畅通需要的最低成本。
输入
Input
测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( 1< N < 100
)；随后的 N(N-1)/2
行对应村庄间道路的成本及修建状态，每行给4个正整数，分别是两个村庄的编号（从1编号到N），此两村庄间道路的成本，以及修建状态：1表示已建，0表示未建。
当N为0时输入结束。
输出
每个测试用例的输出占一行，输出全省畅通需要的最低成本。
样例输入
3
1 2 1 0
1 3 2 0
2 3 4 0
3
1 2 1 0
1 3 2 0
2 3 4 1
3
1 2 1 0
1 3 2 1
2 3 4 1
0
样例输出
3
1
0
*/
#include <bits/stdc++.h>

using namespace std;

#define N 10000

struct edge {
  int s, d, c;
} edge[N];

int p[N];
int n;

int find(int x) {
  if (x != p[x]) {
    return find(p[x]);
  }
  return p[x];
}

int kruskal() {
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
  }
  auto cmp = [&](const struct edge &a, const struct edge &b) {
    return a.c < b.c;
  };
  sort(edge, edge + n * (n - 1) / 2, cmp);
  int cost = 0;
  for (int i = 0; i < n * (n - 1) / 2; ++i) {
    if (find(edge[i].s) != find(edge[i].d)) {
      cost += edge[i].c;
      p[find(edge[i].s)] = find(edge[i].d);
    }
  }
  return cost;
}

int main() {
  while (~scanf("%d", &n)) {
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n * (n - 1) / 2; ++i) {
      int c, f;
      scanf("%d%d%d%d", &edge[i].s, &edge[i].d, &c, &f);
      if (f == 1) {
        edge[i].c = 0;
      } else {
        edge[i].c = c;
      }
    }
    int cost = kruskal();
    printf("%d\n", cost);
  }
  return 0;
}