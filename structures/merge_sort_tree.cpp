#include <bits/stdc++.h>
using namespace std;

// Returns number of elements greater than k in (l, r)
template <typename T> class SegTree {
public:
  int size;
  vector<T> st;
  T NEUTRAL_VALUE = {};

  // Initialize
  void init(int n) {
    size = 1;
    while (size < n) {
      size *= 2;
    }
    st.resize(2 * size);
  }

  // Build
  T merge(T &x, T &y) {
    int i = 0, j = 0, k = 0;
    int n = (int)x.size();
    int m = (int)y.size();
    T res(n + m);
    while (i < n && j < m) {
      if (x[i] < y[j]) {
        res[k++] = x[i++];
      } else {
        res[k++] = y[j++];
      }
    }
    while (i < n) {
      res[k++] = x[i++];
    }
    while (j < m) {
      res[k++] = y[j++];
    }
    return res;
  }
  T single(int v) { return {v}; }
  void build(vector<int> &arr, int x, int lx, int rx) {
    if (lx == rx) {
      if (lx < (int)arr.size())
        st[x] = single(arr[lx]);
      return;
    }
    int mid = (lx + rx) / 2;
    build(arr, 2 * x + 1, lx, mid);
    build(arr, 2 * x + 2, mid + 1, rx);
    st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
  }
  void build(vector<int> &arr) { build(arr, 0, 0, size - 1); }

  // Update
  void set(int x, int lx, int rx, int idx, int val) {
    if (lx == rx) {
      st[x] = val;
      return;
    }
    int mid = (lx + rx) / 2;
    if (idx <= mid) {
      set(2 * x + 1, lx, mid, idx, val);
    } else {
      set(2 * x + 2, mid + 1, rx, idx, val);
    }
    st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
  }
  void set(int idx, int val) { set(0, 0, size - 1, idx, val); }

  // Query
  int query(int x, int lx, int rx, int l, int r, int k) {
    if (r < lx || l > rx) {
      return 0;
    }
    if (lx >= l && rx <= r) {
      return st[x].end() - upper_bound(st[x].begin(), st[x].end(), k);
    }

    int mid = (lx + rx) / 2;
    int q1 = query(2 * x + 1, lx, mid, l, r, k);
    int q2 = query(2 * x + 2, mid + 1, rx, l, r, k);
    return q1 + q2;
  }
  int query(int l, int r, int k) { return query(0, 0, size - 1, l, r, k); }
};
