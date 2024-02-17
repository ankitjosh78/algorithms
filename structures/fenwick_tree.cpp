#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
public:
  int N;
  vector<int> fenwick;
  FenwickTree(int n) : N(n), fenwick(n + 1) {}
  int lsb(int pos) { return pos & -pos; }
  void update(int pos, int val) {
    while (pos <= N) {
      fenwick[pos] += val;
      pos += lsb(pos);
    }
  }
  int query(int pos) {
    int sum = 0;
    while (pos > 0) {
      sum += fenwick[pos];
      pos -= lsb(pos);
    }
    return sum;
  }
};
