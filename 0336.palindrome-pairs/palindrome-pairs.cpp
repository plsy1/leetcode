/*
class Solution {
 public:
  bool f(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right)
      if (s[left++] != s[right--]) return false;
    return true;
  }
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> res;
    for (int i = 0; i != words.size(); ++i)
      for (int j = 0; j != words.size(); ++j) {
        if (i == j) continue;
        if (f(words[i] + words[j])) res.push_back({i, j});
      }
    return res;
  }
};
*/

class Solution {
 public:
  bool f(string& s, int left, int right) {
    while (left < right)
      if (s[left++] != s[right--]) return false;
    return true;
  }
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> res;
    unordered_map<string, int> map;
    set<int> nums;

    for (int i = 0; i != words.size(); ++i) {
      map[words[i]] = i;
      nums.insert(words[i].size());
    }

    for (int i = 0; i != words.size(); ++i) {
      string cur = words[i];
      reverse(cur.begin(), cur.end());
      if (map.count(cur) && map[cur] != i) res.push_back({map[cur], i});
      int len = cur.size();
      for (auto j = nums.begin(); *j != len; ++j) {
        int value = *j;
        if (f(cur, 0, len - value - 1) && map.count(cur.substr(len - value)))
          res.push_back({i, map[cur.substr(len - value)]});
        if (f(cur, value, len - 1) && map.count(cur.substr(0, value)))
          res.push_back({map[cur.substr(0, value)], i});
      }
    }
    return res;
  }
};
