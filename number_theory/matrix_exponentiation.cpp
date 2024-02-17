#include <bits/stdc++.h>
using namespace std;
#define int long long int

int mod = 1e9 + 7;
vector<vector<int>> identity;

void make_identity(int n) {
  identity.resize(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    identity[i][i] = 1;
  }
}
vector<vector<int>> multiply(vector<vector<int>> mat1,
                             vector<vector<int>> mat2) {
  vector<vector<int>> ans(mat1.size(), vector<int>(mat2[0].size(), 0));
  for (int i = 0; i < (int)mat1.size(); i++) {
    for (int j = 0; j < (int)mat2[0].size(); j++) {
      for (int k = 0; k < (int)mat2.size(); k++) {
        ans[i][j] += (mat1[i][k] * 1LL * mat2[k][j]) % mod;
        ans[i][j] %= mod;
      }
    }
  }
  return ans;
}
vector<vector<int>> power(vector<vector<int>> mat, int k) {
  if (k == 0) {
    return identity;
  }
  vector<vector<int>> res = power(mat, k / 2);
  if (k % 2 == 0)
    return multiply(res, res);
  else
    return multiply(multiply(res, res), mat);
}

signed main() {
  int n, k;
  cin >> n >> k;
  make_identity(n);
  vector<vector<int>> mat(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }
  vector<vector<int>> ans = power(mat, k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
