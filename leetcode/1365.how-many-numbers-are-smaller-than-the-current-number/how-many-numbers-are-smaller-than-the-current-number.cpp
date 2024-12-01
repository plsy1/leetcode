class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    int m[101];
    for (int i = tmp.size() - 1; i >= 0; --i) m[tmp[i]] = i;
    for (int i = 0; i < nums.size(); ++i) tmp[i] = m[nums[i]];
    return tmp;
  }
};
