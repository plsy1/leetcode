class Solution {
 public:
  vector<vector<int>> res;
  vector<int> tmp;

  vector<vector<int>> combine(int n, int k) {
    dfs(tmp, n, k, 0);
    return res;
  }

  void dfs(vector<int> tmp, int n, int k, int idx) {
    if (tmp.size() == k) {
      res.push_back(tmp);
      return;
    }
    for (int i = idx + 1; i <= n; ++i) {
      tmp.push_back(i);
      dfs(tmp, n, k, i);
      tmp.pop_back();
    }
  }
};
