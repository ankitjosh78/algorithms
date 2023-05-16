#include <bits/stdc++.h>
#define int long long int
const int mod = 1e9 + 7;
using namespace std;

signed main() {
  int n;
  cin >> n;
  int first = 0, second = 1;
  while (n > 1) {
    int temp = second;
    second = (second + first) % mod;
    first = temp;
    n--;
    cout << second << endl;
  }
}
