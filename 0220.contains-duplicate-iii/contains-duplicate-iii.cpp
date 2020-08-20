class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<double> _set;
    for (int i = 0; i < nums.size(); ++i) {
      auto s = _set.lower_bound((double)nums[i] - (double)t);
      if (s != _set.end() && *s <= (double)nums[i] + (double)t) return true;

      _set.insert(nums[i]);
      if (_set.size() > k) _set.erase(nums[i - k]);
    }
    return false;
  }
};
