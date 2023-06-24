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