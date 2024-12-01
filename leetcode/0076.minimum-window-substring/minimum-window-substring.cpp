class Solution {
 public:
  string minWindow(string s, string t) {
    int m = s.size(), n = t.size();
    unordered_map<char, int> sc, tc;
    int l = 0, r = 0, cnt = 0, min = INT_MAX;
    string res;

    for (auto c : t) ++tc[c];
    while (r < m) {
      char c = s[r];
      ++sc[c];
      if (tc.count(c) && sc[c] <= tc[c]) ++cnt;
      while (l <= r && cnt == n) {
        if (min > r - l + 1) {
          min = r - l + 1;
          res = s.substr(l, min);
        }
        char tmp = s[l];
        --sc[tmp];
        if (tc.count(tmp) && sc[tmp] < tc[tmp]) --cnt;
        ++l;
      }
      ++r;
    }
    return res;
  }
};
