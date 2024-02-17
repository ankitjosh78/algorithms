#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m, vis[MAX_N];
vector<int> adj[MAX_N];

void dfs(int u, int comp) {
  vis[u] = comp;
  for (int v : adj[u]) {
    if (vis[v])
      continue;
    dfs(v, comp);
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int cur_comp = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    cur_comp++;
    dfs(i, cur_comp);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; t++) {
    // cout << "Case #" << t << ": ";
    solve();
  }
}
