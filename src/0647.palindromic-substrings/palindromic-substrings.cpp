class Solution {
 public:
  int countSubstrings(string s) {
    int res = 0;
    for (int i = 0; i != s.size(); ++i) {
      res += f(s, i, i);
      if (i == s.size() - 1) continue;
      res += f(s, i, i + 1);
    }
    return res;
  }
  int f(string& s, int l, int r) {
    int cnt = 0;
    while (l >= 0 && r < s.size() && s[l--] == s[r++]) ++cnt;
    return cnt;
  }
};
