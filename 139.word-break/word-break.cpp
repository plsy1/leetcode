class Solution {
public:
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words;

    for (auto i = 0; i != wordDict.size(); ++i) {
        words.insert(wordDict[i]);
    }
    vector<bool> dp(s.size() + 1);

    dp[0] = true;

    for (auto i = 0; i <= s.size(); ++i) {
        for (auto j = 0; j != i; ++j) {
            if (dp[j] && words.find(s.substr(j, i - j)) != words.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}
};
