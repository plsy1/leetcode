class Solution {
public:
bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size(), l = s3.size();
    int a = 0, b = 0;

    if (m + n != l) return false;

    vector<vector<int> > dp(m + 1, vector<int>(n + 1));

    dp[0][0] = true;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (!i && !j) continue;
            if (i) a = s3[i + j - 1] == s1[i - 1] && dp[i - 1][j];
            if (j) b = s3[i + j - 1] == s2[j - 1] && dp[i][j - 1];
            dp[i][j] = a || b;
        }
    }
    return dp[m][n];
}
};
