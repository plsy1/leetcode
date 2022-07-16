class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    if (len <= 2) return len;
    int slower = 1;

    for (int faster = 2; faster != len; ++faster) {
      if (nums[faster] != nums[slower - 1]) nums[++slower] = nums[faster];
    }
    return slower + 1;
  }
};
