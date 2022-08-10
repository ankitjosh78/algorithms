#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
vector<int> ans;

bool dfs(int v) {
  color[v] = 1;
  for (int u : adj[v]) {
    if (color[u] == 0) {
      if (dfs(u)) {
        return true;
      }
    } else if (color[u] == 1) {
      ans.erase(ans.begin(), ans.end());
      return true;
    }
  }
  color[v] = 2;
  ans.push_back(v);
  return false;
}
int main() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  color.assign(n + 1, false);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (color[i] == 0) {
      if (dfs(i)) {
        ans = {};
        break;
      }
    }
  }
  if (ans.size() == 0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
// 1 0, 0 2, 2 1
