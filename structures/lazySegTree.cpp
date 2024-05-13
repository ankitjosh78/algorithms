// Author: Ankit Josh(f_in_the_chat)

// Lazy Segment Tree to support range updates and range queries:
// 1. (L, R, x) -> increase every A[i] in (L,R) with x
// 2. (L, R, x) -> assign every A[i] in (L,R) with x
// 3. (L, R) -> find sum and max in range (L,R)
#include <bits/stdc++.h>
using namespace std;

struct node {
  int sum;
  int maxr;
  int lazyset = 0;
  int lazyadd = 0;

  node(int val = 0) {
    sum = val;
    maxr = val;
  }
};

vector<int> a;
vector<node> st;

node merge(node &a, node &b) {
  node ans;
  ans.maxr = max(a.maxr, b.maxr);
  ans.sum = a.sum + b.sum;
  return ans;
}

void build(int idx, int l, int r) {
  if (l == r) {
    st[idx] = node(a[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(idx << 1, l, mid);
  build(idx << 1 | 1, mid + 1, r);
  st[idx] = merge(st[idx << 1], st[idx << 1 | 1]);
}

void push(int idx, int l, int r) {
  if (st[idx].lazyset) {
    st[idx].sum = (r - l + 1) * 1LL * st[idx].lazyset;
    st[idx].maxr = st[idx].lazyset;
    if (l < r) {
      st[idx << 1].lazyset = st[idx << 1 | 1].lazyset = st[idx].lazyset;
      st[idx << 1].lazyadd = st[idx << 1 | 1].lazyadd = 0;
    }
    st[idx].lazyset = 0;
  } else if (st[idx].lazyadd) {
    st[idx].sum += (r - l + 1) * 1LL * st[idx].lazyadd;
    st[idx].maxr += st[idx].lazyadd;
    if (l < r) {
      st[idx << 1].lazyadd += st[idx].lazyadd;
      st[idx << 1 | 1].lazyadd += st[idx].lazyadd;
    }
    st[idx].lazyadd = 0;
  }
}

void update(int idx, int l, int r, int lq, int rq, int val, bool set) {
  push(idx, l, r);
  if (l > rq || r < lq)
    return;
  if (lq <= l && r <= rq) {
    if (!set) {
      st[idx].lazyadd += val;
    } else {
      st[idx].lazyset = val;
      st[idx].lazyadd = 0;
    }
    push(idx, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  update(idx << 1, l, mid, lq, rq, val, set);
  update(idx << 1 | 1, mid + 1, r, lq, rq, val, set);
  st[idx] = merge(st[idx << 1], st[idx << 1 | 1]);
}

node query(int idx, int l, int r, int lq, int rq) {
  if (l > rq || r < lq)
    return node(0);
  push(idx, l, r);
  if (lq <= l && r <= rq) {
    return st[idx];
  }
  int mid = (l + r) >> 1;
  node q1 = query(idx << 1, l, mid, lq, rq);
  node q2 = query(idx << 1 | 1, mid + 1, r, lq, rq);
  return merge(q1, q2);
}

int main() {
  int n;
  cin >> n;
  a.resize(n);
  st.resize(4 * n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(1, 0, n - 1);
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      --l;
      --r;
      update(1, 0, n - 1, l, r, x, false);
    } else if (type == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      --l;
      --r;
      update(1, 0, n - 1, l, r, x, true);
    } else if (type == 3) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      cout << query(1, 0, n - 1, l, r).sum << endl;
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      cout << query(1, 0, n - 1, l, r).maxr << endl;
    }
  }
  return 0;
}
