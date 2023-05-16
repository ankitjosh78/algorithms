#include <bits/stdc++.h>
using namespace std;

int n, level;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> anc;

void dfs(int v, int p) {
  tin[v] = ++timer;
  anc[v][0] = p;
  for (int i = 1; i <= level; i++) {
    anc[v][i] = anc[anc[v][i - 1]][i - 1];
  }
  for (int u : adj[v]) {
    if (u != p) {
      dfs(u, v);
    }
  }
  tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (is_ancestor(u, v)) {
    return u;
  }
  if (is_ancestor(v, u)) {
    return v;
  }
  for (int i = level; i >= 0; i--) {
    if (!is_ancestor(anc[u][i], v)) {
      u = anc[u][i];
    }
  }
  return anc[u][0];
}

void preprocess(int root) {
  tin.resize(n);
  tout.resize(n);
  timer = 0;
  level = ceil(log2(n));
  anc.assign(n, vector<int>(level + 1));
  dfs(root, root);
}
