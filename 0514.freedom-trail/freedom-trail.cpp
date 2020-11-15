class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    int lr = ring.size(), lk = key.size(), res = INT_MAX;
    vector<vector<int>> dp(lr, vector<int>(lk, 0));

    for (int j = 0; j != lk; ++j) {
      for (int i = 0; i != lr; ++i) {
        if (ring[i] != key[j]) continue;
        if (j == 0)
          dp[i][0] = min(i, lr - i) + 1;  // two turn methods
        else {
          dp[i][j] = INT_MAX;
          for (int t = 0; t < lr; ++t) {
            if (ring[t] == key[j - 1]) {
              dp[i][j] =
                  min(dp[i][j],
                      dp[t][j - 1] + min(abs(t - i), lr - abs(t - i)) + 1);
            }
          }
        }
        if (j == lk - 1) res = min(res, dp[i][j]);
      }
    }
    return res;
  }
};
