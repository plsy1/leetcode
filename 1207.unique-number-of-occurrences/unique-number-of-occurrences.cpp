class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> m;
    set<int> cnt;
    for (int i = 0; i != arr.size(); ++i) ++m[arr[i]];
    for (int i = 0; i != arr.size(); ++i) cnt.insert(m[arr[i]]);

    return cnt.size() == m.size()
  }
};
