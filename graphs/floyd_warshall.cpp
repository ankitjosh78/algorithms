// Floyd Warshall
// @author: Ankit Josh
// Tested on: https://cses.fi/problemset/task/1672
#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;

const int INF = 1e18;

vector<vector<int>> adj;
int32_t main() {
  int n, m, q;
  cin >> n >> m >> q;
  adj.resize(n, vector<int>(n, INF));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    if (w < adj[u][v])
      adj[u][v] = adj[v][u] = w;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          adj[i][j] = adj[j][i] = 0;
        }
        if (adj[i][k] + adj[k][j] < adj[i][j]) {
          adj[i][j] = adj[j][i] = adj[i][k] + adj[k][j];
        }
      }
    }
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    if (adj[u][v] == 1e18)
      adj[u][v] = -1;
    cout << adj[u][v] << endl;
  }
}
