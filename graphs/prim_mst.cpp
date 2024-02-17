#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;

int prim(int n, vector<vector<pair<int, int>>> &adj) {
  int mst = 0;
  vector<int> dist(n, inf);
  vector<bool> vis(n, false);
  dist[0] = 0;
  set<pair<int, int>> s;
  s.insert(make_pair(0, 0));

  for (int i = 0; i < n; i++) {
    if (s.size() == 0) {
      return -1;
    }
    int u = s.begin()->second;
    vis[u] = true;
    mst += s.begin()->first;
    s.erase(s.begin());

    for (auto x : adj[u]) {
      int v = x.first, w = x.second;
      if (!vis[v] && w < dist[v]) {
        s.erase(make_pair(dist[v], v));
        dist[v] = w;
        s.insert(make_pair(dist[v], v));
      }
    }
  }
  return mst;
}
int main() {
  vector<vector<pair<int, int>>> adj;
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  int cost = prim(n, adj);
  if (cost == -1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << cost << endl;
  }
}
