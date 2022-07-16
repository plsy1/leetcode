class Solution {
public:
int minPathSum(vector<vector<int> >& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    dp[m][n] = grid[m - 1][n - 1];
    for (int i = m - 2; i >= 0; --i) {
        dp[i + 1][n] = dp[i + 2][n] + grid[i][n - 1];
    }
    for (int j = n - 2; j >= 0; --j) {
        dp[m][j + 1] = dp[m][j + 2] + grid[m - 1][j];
    }
    for (int i = m - 2; i >= 0; --i) {
        for (int j = n - 2; j >= 0; --j) {
            dp[i + 1][j + 1] = min(dp[i + 2][j + 1], dp[i + 1][j + 2]) + grid[i][j];
        }
    }
    return dp[1][1];
}
};
