class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    vector<int> tmp(nums);
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < (nums.size() + 1) / 2; ++i) {
      nums[i * 2] = tmp[(nums.size() + 1) / 2 - 1 - i];
    }
    for (int i = 0; i < nums.size() / 2; ++i) {
      nums[i * 2 + 1] = tmp[nums.size() - 1 - i];
    }
  }
};
