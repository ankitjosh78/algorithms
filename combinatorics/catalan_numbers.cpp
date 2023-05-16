#include <bits/stdc++.h>
using namespace std;

// Catalan numbers is a number sequence, which is found useful in a number of
// combinatorial problems, often involving recursively-defined objects.

const int MOD = 1e9 + 7;
const int MAX = 1e5 + 1;
int catalan[MAX];
void calculate_till_n(int n) {
  catalan[0] = catalan[1] = 1;
  for (int i = 2; i <= n; i++) {
    catalan[i] = 0;
    for (int j = 0; j < i; j++) {
      catalan[i] += (catalan[j] * catalan[i - j - 1]) % MOD;
      if (catalan[i] >= MOD) {
        catalan[i] -= MOD;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  calculate_till_n(n);
  cout << catalan[n] << endl;
}
