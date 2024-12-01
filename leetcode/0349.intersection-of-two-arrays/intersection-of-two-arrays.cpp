class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> tmp;
    unordered_map<int, bool> map;
    for (auto i : nums1) {
      map[i] = true;
    }
    for (auto j : nums2) {
      if (map[j]) tmp.insert(j);
    }
    return vector<int>(tmp.begin(), tmp.end());
  }
};
