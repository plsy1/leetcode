class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<int> res;
    unordered_map<char, int> map;
    int l = 0, r = 0;
    for (int i = 0; i < S.size(); ++i) map[S[i]] = i;
    for (int i = 0; i < S.size(); ++i) {
      r = max(r, map[S[i]]);
      if (i == r) {
        res.push_back(r - l + 1);
        l = i + 1;
      }
    }
    return res;
  }
};
