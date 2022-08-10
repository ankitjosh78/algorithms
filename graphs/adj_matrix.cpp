#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph(1e5, vector<int>(1e5, 0));
int main() {
  int n, e;
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    graph[u][v] = 1;
    graph[v][u] = 1;
  }
}
