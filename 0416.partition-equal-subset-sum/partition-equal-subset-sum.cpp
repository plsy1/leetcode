class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    if (nums.size() == 0) return false;
    int sum = 0;
    for (auto i : nums) sum += i;
    if (sum % 2) return false;
    int target = sum / 2;
    vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1));

    if (nums[0] <= target) dp[0][nums[0]] = true;

    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j <= target; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (nums[i] == j) {
          dp[i][j] = true;
          continue;
        }
        if (nums[i] < j) {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
        }
      }
    }
    return dp[nums.size() - 1][target];
  }
};

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    if (nums.size() == 0) return false;
    int sum = 0;
    for (auto i : nums) sum += i;
    if (sum % 2) return false;
    int target = sum / 2;
    vector<bool> dp(target + 1);
    dp[0] = true;

    if (nums[0] <= target) dp[nums[0]] = true;
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = target; nums[i] <= j; --j) {
        if (dp[target]) return true;
        dp[j] = dp[j] || dp[j - nums[i]];
      }
    }
    return dp[target];
  }
};
