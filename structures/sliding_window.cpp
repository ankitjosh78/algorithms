#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MP make_pair

// Sorted Sliding Window using two Multisets.
// Tested on: https://cses.fi/problemset/task/1077/
// Author: Ankit Josh (f_in_the_chat)

class SlidingWindow {
private:
  multiset<pair<int, int>> low, up;
  int lowSum = 0, upSum = 0;

public:
  int uppperHalfSum() { return upSum; }
  int lowerHalfSum() { return lowSum; }
  int median() { return (*low.rbegin()).first; }
  void insert(pair<int, int> p) {
    if (low.size() == 0) {
      low.insert(p);
      lowSum += p.first;
      return;
    }
    if (low.size() > up.size()) {
      if (p.first >= this->median()) {
        up.insert(p);
        upSum += p.first;
        return;
      } else {
        auto x = *low.rbegin();
        low.erase(low.find(x));
        low.insert(p);
        up.insert(x);
        lowSum -= x.first;
        lowSum += p.first;
        upSum += x.first;
        return;
      }
    } else {
      auto x = *up.begin();
      if (p.first < x.first) {
        low.insert(p);
        lowSum += p.first;
      } else {
        up.erase(up.find(x));
        up.insert(p);
        low.insert(x);
        upSum -= x.first;
        upSum += p.first;
        lowSum += x.first;
      }
    }
  }
  void erase(pair<int, int> p) {
    if (p.first > this->median()) {
      up.erase(up.find(p));
      upSum -= p.first;
      if (low.size() - up.size() > 1) {
        auto x = *low.rbegin();
        low.erase(low.find(x));
        up.insert(x);
        lowSum -= x.first;
        upSum += x.first;
      }
      return;
    } else {
      low.erase(low.find(p));
      lowSum -= p.first;
      if (up.size()) {
        auto x = *up.begin();
        up.erase(up.find(x));
        low.insert(x);
        upSum -= x.first;
        lowSum += x.first;
      }
      return;
    }
  }
};

int32_t main() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  SlidingWindow sw;
  for (int i = 0; i < k - 1; i++) {
    sw.insert(MP(a[i], i));
  }
  for (int i = k - 1; i < n; i++) {
    sw.insert(MP(a[i], i));
    cout << abs(sw.uppperHalfSum() -
                (sw.lowerHalfSum() - (k & 1 ? sw.median() : 0)))
         << " ";
    sw.erase(MP(a[i - k + 1], i - k + 1));
  }
  cout << "\n";
  return 0;
}
