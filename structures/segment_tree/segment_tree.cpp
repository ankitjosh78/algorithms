#include <bits/stdc++.h>
using namespace std;

// Segment Tree Class using pointers
// Tested on: https://cses.fi/problemset/task/1648
// Author: Ankit Josh(f_in_the_chat)
template <typename T> class SegTree {
public:
  T data;
  int size;
  SegTree *left;
  SegTree *right;

  SegTree() {
    left = NULL;
    right = NULL;
  }

  ~SegTree() {
    delete left;
    delete right;
  }

  void makeChild() {
    if (this->left == NULL)
      this->left = new SegTree();
    if (this->right == NULL)
      this->right = new SegTree();
  }

  void init(int n) {
    size = 1;
    while (size < n) {
      size *= 2;
    }
  }

  // Merge
  T merge(T x, T y) { return (x + y); }
  // Single element
  T single(int v) { return 0; }

  void build(SegTree<T> *root, vector<int> &arr, int lx, int rx) {
    if (lx == rx) {
      if (lx < (int)arr.size())
        root->data = single(arr[lx]);
      return;
    }
    int mid = (lx + rx) / 2;
    root->makeChild();
    build(root->left, arr, lx, mid);
    build(root->right, arr, mid + 1, rx);
    root->data = merge(root->left->data, root->right->data);
  }
  void build(SegTree<T> *root, vector<int> &arr) {
    build(root, arr, 0, size - 1);
  }

  // Update
  void set(SegTree<T> *root, int lx, int rx, int idx, int val) {
    if (lx == rx) {
      root->data++;
      return;
    }
    int mid = (lx + rx) / 2;
    if (idx <= mid) {
      set(root->left, lx, mid, idx, val);
    } else {
      set(root->right, mid + 1, rx, idx, val);
    }
    root->data = merge(root->left->data, root->right->data);
  }
  void set(SegTree<T> *root, int idx, int val) {
    set(root, 0, size - 1, idx, val);
  }

  // Query
  T query(SegTree<T> *root, int lx, int rx, int l, int r) {
    if (rx < l || r < lx) {
      return 0;
    }
    if (lx >= l && rx <= r) {
      return root->data;
    }
    int mid = (lx + rx) / 2;
    T q1 = query(root->left, lx, mid, l, r);
    T q2 = query(root->right, mid + 1, rx, l, r);
    return merge(q1, q2);
  }
  T query(SegTree<T> *root, int l, int r) {
    return query(root, 0, size - 1, l, r);
  }
};

const bool cmp(pair<int, int> &a, pair<int, int> &b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}

int main() {
  int n;
  cin >> n;

  SegTree<int> *st = new SegTree<int>();
  st->init(n);
  vector<int> a(n);
  vector<int> ans(n);
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    arr[i] = make_pair(a[i], i);
  }
  st->build(st, a);
  sort(arr.begin(), arr.end(), cmp);
  for (auto [x, idx] : arr) {
    ans[idx] = st->query(st, 0, idx - 1);
    st->set(st, idx, x);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  cout << endl;
}
