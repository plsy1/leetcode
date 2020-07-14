class Solution {
public:
int respace(vector<string>& dictionary, string sentence) {
    int n = sentence.size();
    int dp[n + 1];

    dp[0] = 0;
    for (int i = 0; i != n; ++i) {
        dp[i + 1] = dp[i] + 1;
        for (auto s : dictionary) {
            if (s.size() <= i + 1)
                if (s == sentence.substr(i + 1 - s.size(), s.size() ))
                    dp[i + 1] = min(dp[i + 1], dp[i + 1 - s.size()]);
        }
    }
    return dp[n];
}
};
