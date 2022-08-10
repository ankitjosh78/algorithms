// SPOJ: PRIME1
#include "bits/stdc++.h"
#define int long long int
using namespace std;

vector<int> primes;
void seive(int n) {
  vector<bool> is_prime(n + 1, true);
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
}
void segSeive(int low, int high) {
  int nsqrt = sqrt(high);
  seive(nsqrt);
  vector<bool> is_prime(high - low + 1, true);
  for (auto p : primes) {
    int firstMultiple = (low / p) * p;
    if (firstMultiple < low) {
      firstMultiple += p;
    }
    int start = max(firstMultiple, p * p);
    for (int i = start; i <= high; i += p) {
      is_prime[i - low] = false;
    }
  }
  if (low == 1)
    is_prime[0] = false;
  for (int i = low; i <= high; i++) {
    if (is_prime[i - low])
      cout << i << endl;
  }
  cout << endl;
}
void solve() {
  int low, high;
  cin >> low >> high;
  segSeive(low, high);
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
