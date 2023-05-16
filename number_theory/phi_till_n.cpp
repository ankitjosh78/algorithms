#include <bits/stdc++.h>
#define lli long long int
using namespace std;

const int MOD = 1e9 + 7;
vector<lli> phi(2e5 + 1);
vector<lli> prefix(2e5 + 1);
void phi_1_to_n(lli n) {
  for (lli i = 0; i <= n; i++)
    phi[i] = i;

  for (lli i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (lli j = i; j <= n; j += i)
        phi[j] -= phi[j] / i;
    }
  }
}

signed main() {
  phi_1_to_n(1e5);
  prefix[1] = 1;
  for (int i = 2; i <= 1e5; i++) {
    prefix[i] = (prefix[i - 1] % MOD + phi[i] % MOD) % MOD;
  }
  int t;
  cin >> t;
  while (t--) {
    lli n;
    cin >> n;
    lli ans = 0;
    for (lli i = 1; i <= n; i++) {
      ans = (ans + (prefix[i] * phi[i]) % MOD) % MOD;
    }
    cout << ans << endl;
  }
}
