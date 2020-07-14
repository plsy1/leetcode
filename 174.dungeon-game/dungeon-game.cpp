class Solution {
public:
int calculateMinimumHP(vector<vector<int> >& dungeon) {
    int n = dungeon.size(), m = dungeon[0].size();
    int temp = 0;
    int dp[n + 1][m + 1];

    dp[n - 1][m] = 1;
    dp[n][m - 1] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            temp = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(1, temp - dungeon[i][j]);
        }
    }
    return dp[0][0];
}
};
