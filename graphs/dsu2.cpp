#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> link, size;

int find(int x) {
  while (x != link[x])
    x = link[x];
  return x;
}

bool same(int a, int b) { return find(a) == find(b); }

void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (size[a] < size[b])
    swap(a, b);
  size[a] += size[b];
  size[b] = 0;
  link[b] = a;
}

int main() {
  int n;
  int m;
  link.resize(n + 1);
  for (int i = 1; i <= n; i++)
    link[i] = i;
  for (int i = 1; i <= n; i++)
    size[i] = 1;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    unite(u, v);
  }
}
