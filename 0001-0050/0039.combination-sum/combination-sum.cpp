class Solution {
 public:
  vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    sort(candidates.rbegin(), candidates.rend());
    coin(candidates, target, 0);
    return res;
  }

 private:
  vector<vector<int> > res;
  vector<int> cur;
  void coin(vector<int>& candidates, int target, int idx) {
    if (target == 0) {
      res.push_back(cur);
      return;
    }
    if (idx == candidates.size() || target < 0) return;
    int candidate = candidates[idx];

    for (int i = target / candidate; i > 0; --i) {
      cur.push_back(candidate);
    }
    for (int j = target / candidate; j >= 0; --j) {
      coin(candidates, target - candidate * j, idx + 1);
      if (j > 0) cur.pop_back();
    }
  }
};
