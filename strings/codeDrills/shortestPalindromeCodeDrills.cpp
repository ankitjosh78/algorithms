#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ShortestPalindrome {
public:
  // DO NOT read from stdin or write to stdout.
  // Input is given as the function arguments.
  // Output is taken as the function return value.
  int res = 1;
  vector<vector<int>> dp;
  int func(int i, int j, string &s) {
    if (i == j) {
      return dp[i][j] = 1;
    }
    if (i > j) {
      return dp[i][j] = 0;
    }
    if (i == j - 1) {
      if (s[i] == s[j]) {
        return dp[i][j] = 0;
      } else {
        return dp[i][j] = 2;
      }
    }
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s[i] == s[j]) {
      int ans1 = func(i, j - 1, s);
      if (ans1 == j - i) {
        dp[i][j] = max(dp[i][j], ans1);
      }
      int ans2 = func(i + 1, j - 1, s);
      if (ans2 == j - i - 2) {
        dp[i][j] = max(dp[i][j], ans2 + 2);
      }
      return dp[i][j];
    } else {
      return dp[i][j] = func(i, j - 1, s);
    }
  }
  string getShortestPalindomeString(string s) {
    dp.resize(s.size(), vector<int>(s.size(), -1));
    func(0, (int)s.size() - 1, s);
    int res = 1;
    string ans = "";
    for (int i = 0; i < (int)s.size(); i++) {
      res = max(res, dp[0][i]);
    }
    // cout << res << endl;
    for (int i = res + 1; i < (int)s.size(); i++) {
      ans.push_back(s[i]);
    }
    reverse(ans.begin(), ans.end());
    ans += s;
    // cout << ans << endl;
    return ans;
  }
};

// TC: O(n^2)
// SC: O(n^2)
