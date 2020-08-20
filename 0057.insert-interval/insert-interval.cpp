class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    intervals.push_back({newInterval[0], newInterval[1]});
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    for (int i = 0; i != intervals.size();) {
      int r = intervals[i][1];
      int j = i + 1;
      while (j < intervals.size() && intervals[j][0] <= r) {
        r = max(r, intervals[j][1]);
        ++j;
      }
      res.push_back({intervals[i][0], r});
      i = j;
    }
    return res;
  }
};
