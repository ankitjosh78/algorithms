#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
vector<int> parent;
int cycle_start = -1, cycle_end = -1;

bool dfs(int v) {
  color[v] = 1;
  for (int u : adj[v]) {
    if (color[u] == 0) {
      parent[u] = v;
      if (dfs(u)) {
        return true;
      }
    } else if (color[u] == 1) {
      cycle_end = v;
      cycle_start = u;
      return true;
    }
  }
  color[v] = 2;
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  color.assign(n + 1, 0);
  parent.assign(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  bool ans = false;
  for (int i = 1; i <= n; i++) {
    if (color[i] == 0 && dfs(i)) {
      ans = true;
      break;
    }
  }
  if (ans == false) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  vector<int> cycle;
  cycle.push_back(cycle_start);
  for (int i = cycle_end; i != cycle_start; i = parent[i]) {
    cycle.push_back(i);
  }
  cycle.push_back(cycle_start);
  reverse(cycle.begin(), cycle.end());
  cout << cycle.size() << endl;
  for (auto x : cycle) {
    cout << x << " ";
  }
  cout << endl;
}
