#include <bits/stdc++.h>
using namespace std;

// Coordinate compress array from 0 to N-1
void coordinate_compression(vector<int> &a) {
  set<int> coordinates;
  for (int x : a)
    coordinates.insert(x);
  map<int, int> compression;
  int counter = 0;
  for (int x : coordinates) {
    compression[x] = counter++;
  }
  for (int i = 0; i < (int)a.size(); i++) {
    a[i] = compression[a[i]];
  }
  return;
}
int main() {
  vector<int> a = {100, 400, 300, 200};
  coordinate_compression(a);
  for (int x : a) {
    cout << x << " ";
  }
}
