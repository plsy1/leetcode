class Solution {
public:
vector<string> letterCombinations(string digits) {
    vector<string> res;
    map<char, string> message = { { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };
    int len = digits.size();
    queue<string> que;

    // 将digits[0]所对应的值入队
    for (int i = 0; i < message[digits[0]].size(); ++i) {
        string str;
        str.push_back(m[digits[0]][i]);
        que.push(str);
    }

    string s;

    for (int j = 1; j < len; ++j) {
        int qLen = que.size();
        while (qLen--) {
            for (int k = 0; k < m[digits[j]].size(); ++k) {
                s = que.front();
                s = s + m[digits[j]][k];
                que.push(s)
            }
            que.pop();
        }
    }
    while (!que.empty()) {
        res.push_back(que.front());
        que.pop();
    }
    return res;
} // letterCombinations
};
