// Single Source Shortest Path
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> distTo;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int main() {
  int n, e;
  cin >> n >> e;
  adj.resize(n);
  distTo.resize(n, INT_MAX);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  int src;
  cin >> src;
  distTo[src] = 0;
  pq.push(make_pair(0, src));
  while (pq.size() != 0) {
    int curNode = pq.top().second;
    int curNodeDist = pq.top().first;
    pq.pop();
    for (pair<int, int> u : adj[curNode]) {
      int nextNode = u.first;
      int nextNodeDistFromCur = u.second;
      if (distTo[nextNode] > curNodeDist + nextNodeDistFromCur) {
        distTo[nextNode] = curNodeDist + nextNodeDistFromCur;
        pq.push(make_pair(distTo[nextNode], nextNode));
      }
    }
  }
}
