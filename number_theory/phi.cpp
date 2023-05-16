#include <bits/stdc++.h>
#define int long long int
using namespace std;

int phi(int n) {
  vector<int> factors;
  int num = n;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      while (n % i == 0)
        n = n / i;
      factors.push_back(i);
    }
  }
  if (n > 1) {
    factors.push_back(n);
  }
  int res = num;
  for (int x : factors) {
    res -= res / x;
  }
  return res;
}

signed main() {
  int n;
  cin >> n;
  cout << phi(n) << endl;
}
