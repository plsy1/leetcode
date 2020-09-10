class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    this->candidates = candidates;
    dfs(target, 0);
    return res;
  }

 private:
  vector<vector<int>> res;
  vector<int> tmp;
  vector<int> candidates;

  void dfs(int target, int idx) {
    if (target == 0) {
      res.push_back(tmp);
      return;
    }
    for (int i = idx; i != candidates.size() && target - candidates[i] >= 0;
         ++i) {
      if (i > idx && candidates[i] == candidates[i - 1]) continue;
      tmp.push_back(candidates[i]);
      dfs(target - candidates[i], i + 1);
      tmp.pop_back();
    }
  }
};
