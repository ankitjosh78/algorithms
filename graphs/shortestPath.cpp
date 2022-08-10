#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> adj_list(1e5);
vector<bool> used(1e5);
vector<int> dist(1e5);
vector<int> parent(1e5);
int main() {
  int n, e;
  cout << "Enter no. of nodes and edges" << endl;
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  cout << "Enter source vertex:" << endl;
  int s;
  cin >> s;
  queue<int> q;
  q.push(s);
  used[s] = true;
  parent[s] = -1;
  while (q.size() != 0) {
    int v = q.front();
    q.pop();
    for (auto u : adj_list[v]) {
      if (!used[u]) {
        q.push(u);
        used[u] = true;
        dist[u] = dist[v] + 1;
        parent[u] = v;
      }
    }
  }
  cout << "Enter the destination vertex:" << endl;
  int dest;
  cin >> dest;
  if (!used[dest]) {
    cout << "No Path!" << endl;
  } else {
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v]) {
      path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int u : path) {
      cout << u << " ";
    }
  }
}
