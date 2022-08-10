#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> timings;
  for (int i = 0; i < n; i++) {
    cin >> timings[i].first >> timings[i].second;
  }
  // maximum number of different customers at any time?
  // 4 <- 2, 8 <- 5, 9 <- 3
  // before ones' leaving if another one is inside then ok.
}
