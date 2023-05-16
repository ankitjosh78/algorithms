#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// calculating binary exponentiation of a^b efficiently
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

int main() {}
