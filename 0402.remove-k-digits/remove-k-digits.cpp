class Solution {
 public:
  string removeKdigits(string num, int k) {
    string res;
    int n = num.size() - k;
    for (auto c : num) {
      while (k && num.size() && res.back() > c) {
        res.pop_back();
        --k;
      }
      res.push_back(c);
    }
    res.resize(n);
    while (!res.empty() && res[0] == '0') res.erase(res.begin());
    return res.empty() ? "0" : res;
  }
};
