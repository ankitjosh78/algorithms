#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> adj;
vector<int> color;
bool dfs(int v) {
  color[v] = 1;
  for (int u : adj[v]) {
    if (color[u] == 0) {
      if (dfs(u))
        return true;
    } else if (color[u] == 1) {
      return true;
    }
  }
  color[v] = 2;
  return false;
}
int main() {
  int n;
  int e;
  cin >> n >> e;
  adj.resize(n);
  color.assign(n, 0);
  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (color[i] == 0 && dfs(i)) {
      ans = 1;
      break;
    }
  }
  cout << (ans ? "Cyclic" : "Acyclic") << endl;
}
