class Solution {
public:
int translateNum(int num) {
    stringstream ss;
    string value;

    ss << num;
    ss >> value;
    vector<int> dp(value.size() + 1, 0);

    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i < dp.size(); ++i) {
        dp[i] += dp[i - 1];
        if (value[i - 2] != '1' && value[i - 2] != '2') continue;
        if (value[i - 2] == '2' && value[i - 1] > '5') continue;
        dp[i] += dp[i - 2];
    }
    return dp[value.size()];

}
};
