#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_N = 150005;

// union by size
vector<int> adj[MAX_N];
int label[MAX_N];  // label or id of each component
int sz[MAX_N];     // size of each component
int nedges[MAX_N]; // no. of edges for each component

// relabelling a component
void relabel(int v, int target) {
  if (label[v] == target)
    return;
  label[v] = target;
  for (int u : adj[v]) {
    relabel(u, target);
  }
}

// merging two component
void merge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);

  if (label[u] == label[v]) {
    nedges[label[u]]++;
    return;
  }

  if (sz[label[u]] > sz[label[v]]) {
    swap(u, v);
  }

  sz[label[v]] += sz[label[u]];
  sz[label[u]] = 0;
  nedges[label[v]] += (nedges[label[u]] + 1);
  nedges[label[u]] = 0;
  relabel(u, label[v]);
}

int find(int v) { return label[v]; }

signed main() {
  int nodes, edges;
  cin >> nodes >> edges;
  for (int i = 0; i < nodes; i++) {
    label[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < edges; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    merge(u, v);
  }
}
