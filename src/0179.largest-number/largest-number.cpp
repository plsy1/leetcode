class Solution {
 public:
  static bool cmp(const int& a, const int& b) {
    string m = to_string(a) + to_string(b);
    string n = to_string(b) + to_string(a);

    return m > n;
  }
  string largestNumber(vector<int>& nums) {
    if (nums.empty()) return "";
    if (nums.size() == 1) return to_string(nums[0]);
    sort(nums.begin(), nums.end(), cmp);
    string res;
    for (auto i : nums) {
      res += to_string(i);
    }
    if (res[0] == '0') return "0";
    return res;
  }
};
