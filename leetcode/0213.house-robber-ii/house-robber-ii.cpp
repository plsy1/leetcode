class Solution {
 public:
  int rob(vector<int> &nums) {
    int len = nums.size();
    if (len == 0) return 0;
    if (len == 1) return nums[0];
    int dp[len - 1][2];
    int dp1[len][2];
    dp[0][1] = nums[0];
    dp[0][0] = 0;
    for (int i = 1; i != len - 1; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = dp[i - 1][0] + nums[i];
    }
    dp1[1][1] = nums[1];
    for (int i = 2; i != len; ++i) {
      dp1[i][0] = max(dp1[i - 1][0], dp1[i - 1][1]);
      dp1[i][1] = dp1[i - 1][0] + nums[i];
    }
    int m = max(dp[len - 2][0], dp[len - 2][1]);
    int n = max(dp1[len - 1][0], dp[len - 1][1]);
    return max(m, n);
  }
};
