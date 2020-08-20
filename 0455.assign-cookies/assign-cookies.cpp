class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    int cnt = 0, child = 0, cookies = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    while (child < g.size() && cookies < s.size()) {
      if (g[child] <= s[cookies]) ++child;
      ++cookies;
    }
    return child;
  }
};
