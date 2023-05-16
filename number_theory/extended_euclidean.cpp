// Euclid Problem:
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045
#include <bits/stdc++.h>
using namespace std;

int extended_euclidean(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int g = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

int main() {
  int a, b;
  while (cin >> a) {
    cin >> b;
    int x, y;
    int res = extended_euclidean(a, b, x, y);
    cout << x << " " << y << endl;
  }
  return 0;
}
