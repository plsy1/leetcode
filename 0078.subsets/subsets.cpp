/*某大佬的位运算*/
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int S = nums.size();
    int N = 1 << S;
    vector<vector<int>> res;

    for (int i = 0; i != N; ++i) {
      vector<int> v;
      for (int j = 0; j != S; ++j) {
        if (i & (1 << j)) v.push_back(nums[j]);
      }
      res.push_back(v);
    }
    return res;
  }
};

/*回溯*/
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    this->nums = nums;
    dfs(0);
    return res;
  }

 private:
  vector<vector<int>> res;
  vector<int> tmp;
  vector<int> nums;

  void dfs(int idx) {
    res.push_back(tmp);
    for (int i = idx; i != nums.size(); ++i) {
      tmp.push_back(nums[i]);
      dfs(i + 1);
      tmp.pop_back();
    }
  }
};
