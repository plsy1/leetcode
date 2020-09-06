class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = s[i - 1] == '0' ? 0 : dp[i - 1];
      int x = atoi(s.substr(i - 2, 2).c_str());

      if (x >= 10 && x <= 26) dp[i] += dp[i - 2];
    }
    return dp[n];
  }
};
