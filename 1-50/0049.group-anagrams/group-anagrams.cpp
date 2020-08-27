class Solution {
public:
vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > res;
    unordered_map <int, vector<string> > m;
    int a[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };

    for (string& s : strs) {
        int t = 1;
        for (char c : s) {
            t *= a[c - 'a'];
        }

        m[t].push_back(s);
    }
    for (auto& n : m) {
        res.push_back(n.second);
    }
    return res;
}
};
