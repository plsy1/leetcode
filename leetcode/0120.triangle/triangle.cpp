class Solution {
public:
int minimumTotal(vector<vector<int> >& triangle) {
    if (triangle.size() == 0 || triangle[0].size() == 0)
        return 0;
    int len = triangle.size();
    vector<int> dp(triangle[len - 1]);

    for (int i = len - 2; i >= 0; --i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        }
    }

    return dp[0];
}
};
