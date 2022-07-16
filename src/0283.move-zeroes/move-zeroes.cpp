class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    stable_sort(nums.begin(), nums.end(), [](int, int b) {
      if (b == 0) return true;
      return false;
    });
  }
};

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0;
    while (i < nums.size()) {
      if (nums[i]) swap(nums[j++], nums[i]);
      ++i;
    }
  }
};
