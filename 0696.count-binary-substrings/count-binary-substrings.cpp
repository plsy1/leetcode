class Solution {
 public:
  int m = 1, n = 0, res = 0;
  int countBinarySubstrings(string s) {
    for (int i = 1; i != s.size(); ++i) {
      if (s[i] == s[i - 1])
        ++m;
      else {
        n = m;
        m = 1;
      }
      if (n >= m) ++res;
    }
    return res;
  }
};
