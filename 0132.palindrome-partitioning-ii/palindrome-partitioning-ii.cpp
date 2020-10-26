class Solution {
 public:
  int minCut(string s) {
    int len = s.size();
    if (len < 2) return 0;
    int dp[len];
    for (int i = 0; i < len; ++i) dp[i] = i;
    for (int i = 1; i < len; ++i) {
      if (isPalindrome(s, 0, i)) {
        dp[i] = 0;
        continue;
      }
      for (int j = 0; j < i; ++j) {
        if (isPalindrome(s, j + 1, i)) dp[i] = min(dp[i], dp[j] + 1);
      }
    }
    return dp[len - 1];
  }

 private:
  bool isPalindrome(string s, int l, int r) {
    while (l < r) {
      if (s[l++] != s[r--]) return false;
    }
    return true;
  }
};
