/**
题目描述
PIPI给你一个合法的括号序列，希望跟你按左括号下标递增顺序给出每对括号在序列中的下标。（下标从1开始）
输入
多组数据，请处理到EOF。
对于每组数据，第一行包括一个只包含'(',')'的字符串，保证输入的括号匹配序列合法，长度不超过100000
输出
按左括号下标递增顺序给出每对括号在序列中的下标。
样例输入
(())()()
样例输出
1 4
2 3
5 6
7 8
提示
注意输出时的顺序哦~
*/
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <utility>

using namespace std;

int main() {
  string str;
  while (cin >> str) {
    stack<int> st;
    int size = str.size();
    map<int, int> mp;
    for (int i = 0; i < size; ++i) {
      if (str[i] == '(') {
        st.push(i);
      } else {
        int left = st.top();
        st.pop();
        mp[left + 1] = i + 1;
      }
    }
    for (const auto &it : mp) {
      // TLE
      // std::cout << it.first << " " << it.second << endl;
      printf("%d %d\n", it.first, it.second);
    }
  }
  return 0;
}