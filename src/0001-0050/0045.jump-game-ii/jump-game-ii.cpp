class Solution {
 public:
  int max(int a, int b) {
    if (a > b)
      return a;
    else
      return b;
  }

  int jump(vector<int>& nums) {
    int len = end(nums) - begin(nums);
    int end = 0;
    int maxpos = 0;
    int res = 0;
    for (int i = 0; i < len - 1; i++) {
      maxpos = max(maxpos, i + nums[i]);
      if (end == i) {
        end = maxpos;
        res++;
      }
    }
    return res;
  }
};
