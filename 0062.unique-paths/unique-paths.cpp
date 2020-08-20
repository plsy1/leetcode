class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 1 && n == 1) return 1;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i != m; ++i) dp[n][i] = 1;
    for (int i = 1; i != n; ++i) dp[i][m] = 1;

    for (int i = n - 1; i != 0; --i)
      for (int j = m - 1; j != 0; --j) dp[i][j] = dp[i + 1][j] + dp[i][j + 1];

    return dp[1][1];
  }
};
