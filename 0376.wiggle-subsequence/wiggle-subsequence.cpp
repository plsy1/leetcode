class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int down = 1, up = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1])
        up = down + 1;
      else if (nums[i] < nums[i - 1])
        down = up + 1;
    }
    return nums.size() == 0 ? 0 : max(down, up);
  }
};
