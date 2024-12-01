class Solution {
public:

int maxCoins(vector<int>& nums) {
    int n = nums.size();

    vector<int> p(n + 2, 1);

    for (int i = 1; i <= n; i++) {
        p[i] = nums[i - 1];
    }

    vector<vector<int> > f(n + 2, vector<int> (n + 2, 0));

    for (int i = n; i > 0; i--) {
        for (int j = i; j <= n; j++) {
            for (int k = i; k <= j; k++) {
                f[i][j] = max(f[i][j], f[i][k - 1] + f[k + 1][j] + p[i - 1] * p[k] * p[j + 1]);
            }
        }
    }

    return f[1][n];

} // maxCoins
};
