class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](auto& m, auto& n) {
      return m[0] > n[0] || (m[0] == n[0] && m[1] < n[1]);
    });

    vector<vector<int>> res;
    for (auto& iter : people) {
      auto pos = res.begin();
      advance(pos, iter[1]);
      res.insert(pos, iter);
    }
    return res;
  }
};
