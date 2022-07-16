class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    this->nums = nums;
    f(0, nums.size() - 1);
    return res;
  }

 private:
  vector<vector<int>> res;
  vector<int> nums;

  void f(int begin, int end) {
    if (begin == end) res.push_back(nums);
    unordered_set<int> s;
    for (int i = begin; i <= end; ++i) {
      if (s.count(nums[i])) continue;
      swap(nums[i], nums[begin]);
      f(begin + 1, end);
      swap(nums[i], nums[begin]);
      s.insert(nums[i]);
    }
  }
};
