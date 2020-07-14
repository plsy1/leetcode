class Solution {
public:
int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int dp0 = -prices[0], dp1 = 0, dp2 = 0;

    for (int i = 1; i != prices.size(); ++i) {
        dp0 = max(dp0, dp1 - prices[i]);
        dp1 = max(dp1, dp2);
        dp2 = dp0 + prices[i];
    }

    return max(dp1, dp2);
}
};
