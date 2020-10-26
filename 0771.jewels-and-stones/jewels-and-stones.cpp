class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    unordered_map<char, bool> m;
    int res = 0;
    for (auto c : J) m[c] = true;
    for (auto i : S) {
      if (m[i]) ++res;
    }
    return res;
  }
};
