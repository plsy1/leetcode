class Solution {
 public:
  vector<vector<int>> res;
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> tmp;
    process(0, nums, tmp);
    return res;
  }
  void process(int start, vector<int>& nums, vector<int>& tmp) {
    if (tmp.size() <= nums.size()) {
      res.push_back(tmp);
    }
    for (int i = start; i < nums.size(); i++) {
      if (i != start && nums[i] == nums[i - 1]) continue;
      tmp.push_back(nums[i]);
      process(i + 1, nums, tmp);
      tmp.pop_back();
    }
  }
};
