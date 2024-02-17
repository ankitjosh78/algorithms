#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;
bool is_bipartite = true;

// Color 1, 2
void dfs(int node, int color) {
  vis[node] = color;
  for (int v : adj[node]) {
    if (!vis[v]) {
      dfs(v, 3 ^ color);
    } else {
      if (vis[v] == vis[node])
        is_bipartite = false;
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  adj.clear();
  adj.resize(n + 1);
  vis.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i])
      dfs(i, 1);
  }
  cout << (is_bipartite ? "YES" : "NO") << endl;
}
