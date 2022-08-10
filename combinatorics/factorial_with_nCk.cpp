#include <bits/stdc++.h>

using namespace std;

// modulo value
const long long p = 1e9 + 7;
// max_size of n
const int MAXN = 1e5;

vector<long long> fact(MAXN + 1);

// precomputing factorial from 1 to n
void calculateFact() {
  fact[0] = fact[1] = 1;
  for (long long i = 2; i <= (long long)MAXN; i++) {
    fact[i] = (fact[i - 1] * i) % p;
  }
}

// fernet's little theorem using binary exponentiation
long long powmod(long long a, long long b, long long p) {
  a %= p;
  if (a == 0)
    return 0;
  long long product = 1;
  while (b > 0) {
    if (b & 1) {
      product *= a;
      product %= p;
      --b;
    }
    a *= a;
    a %= p;
    b /= 2;
  }
  return product;
}

// modular inverse
long long inv(long long a, long long p) { return powmod(a, p - 2, p); }

// returns nCk modulo p
long long nCk(long long n, long long k, long long p) {
  return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}
