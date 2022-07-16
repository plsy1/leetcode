class Solution {
 public:
  vector<vector<int>> res;
  vector<int> tmp;
  int cnt;
  vector<vector<int>> combinationSum3(int k, int n) {
    cnt = k;
    dfs(k, n, 1);
    return res;
  }
  void dfs(int k, int n, int idx) {
    if (n == 0 && tmp.size() == cnt) {
      res.push_back(tmp);
      return;
    }
    for (int i = idx; i <= 9; ++i) {
      tmp.push_back(i);
      dfs(k - 1, n - i, i + 1);
      tmp.pop_back();
    }
  }
};
