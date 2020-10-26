class Solution {
 public:
  vector<vector<string>> partition(string s) {
    backtrack(s, 0, s.size() - 1);
    return res;
  }

 private:
  vector<string> tmp;
  vector<vector<string>> res;
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (s[l++] != s[r--]) return false;
    }
    return true;
  }

  void backtrack(string s, int a, int b) {
    if (a > b) {
      res.push_back(tmp);
      return;
    }
    for (int i = 1; i <= b - a + 1; i++) {
      if (isPalindrome(s.substr(a, i))) {
        tmp.push_back(s.substr(a, i));
        backtrack(s, a + i, b);
        tmp.pop_back();
      }
    }
  }
};
