// SPOJ: The Last Digit
#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  if (b == 0) {
    cout << 1 << endl;
    return 0;
  }
  a = a % 10;
  b = (b % 4 == 0 ? 4 : b % 4);
  cout << (long long)pow(a, b) % 10 << endl;
}
