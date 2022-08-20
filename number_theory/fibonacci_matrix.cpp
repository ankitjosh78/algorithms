#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int mod = 1e9 + 7;
vector<vector<int>> identity = {{1, 0}, {0, 1}};

vector<vector<int>> multiply(vector<vector<int>> mat1,
                             vector<vector<int>> mat2) {
  vector<vector<int>> ans(mat1.size(), vector<int>(mat2[0].size(), 0));
  for (int i = 0; i < (int)mat1.size(); i++) {
    for (int j = 0; j < (int)mat2[0].size(); j++) {
      for (int k = 0; k < (int)mat2.size(); k++) {
        ans[i][j] = (ans[i][j] + mat1[i][k] * mat2[k][j]) % mod;
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
  if (k & 1) {
    return multiply(multiply(res, res), mat);
  } else
    return multiply(res, res);
}

signed main() {
  int n;
  cin >> n;
  vector<vector<int>> fib = {{1, 1}, {1, 0}};
  vector<vector<int>> res = multiply(power(fib, n - 1), {{1}, {0}});
  cout << res[0][0] << endl;
}
