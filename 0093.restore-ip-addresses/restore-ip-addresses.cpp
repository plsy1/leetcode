class Solution {
 public:
  vector<string> res;
  void dfs(string s, string cur, int count) {
    if (count == 4) {
      if (s.empty()) res.push_back(cur);
    } else {
      for (int k = 1; k != 4; ++k) {
        if (s.size() < k) break;
        int val = stoi(s.substr(0, k));
        if (val > 255 || k != std::to_string(val).size()) continue;
        dfs(s.substr(k), cur + s.substr(0, k) + (count == 3 ? "" : "."),
            count + 1);
      }
    }
    return;
  }

  vector<string> restoreIpAddresses(string s) {
    string cur;
    dfs(s, cur, 0);
    return res;
  }
};
