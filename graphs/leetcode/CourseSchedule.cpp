#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<int>> adj;
  vector<int> color;
  bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
      if (color[u] == 0) {
        if (dfs(u)) {
          return true;
        }
      } else if (color[u] == 1) {
        return true;
      }
    }
    color[v] = 2;
    return false;
  }

public:
  bool canFinish(int n, vector<vector<int>> &pre) {
    if (pre.size() == 0) {
      return true;
    }
    adj.resize(n);
    color.resize(n, 0);
    for (auto needs : pre) {
      adj[needs[0]].push_back(needs[1]);
    }
    bool ans = 1;
    for (int i = 0; i < n; i++) {
      if (color[i] == 0 && dfs(i)) {
        ans = 0;
        break;
      }
    }
    return ans;
  }
};
