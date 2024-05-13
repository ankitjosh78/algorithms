#include <bits/stdc++.h>
using namespace std;

const int max_n = 1e7 + 5;
int spf[max_n];
bool vis[max_n];

void seive() {
  for (int i = 1; i < max_n; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < max_n; i += 2) {
    spf[i] = 2;
  }
  for (int i = 3; i < max_n; i += 2) {
    if (!vis[i]) {
      spf[i] = i;
      for (int j = i; (j * 1LL * i) < max_n; j += 2) {
        if (!vis[j * i]) {
          spf[j * i] = i;
          vis[j * i] = true;
        }
      }
    }
  }
}

int main() { seive(); }
