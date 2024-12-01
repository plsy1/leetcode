class Solution {
 public:
  int rob(vector<int> &nums) {
    int len = nums.size();
    if (len == 0) return 0;
    if (len == 1) return nums[0];
    int dp[len][2];
    dp[0][1] = nums[0];
    dp[0][0] = 0;
    for (int i = 1; i != len; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = dp[i - 1][0] + nums[i];
    }
    return max(dp[len - 1][0], dp[len - 1][1]);
  }
};
