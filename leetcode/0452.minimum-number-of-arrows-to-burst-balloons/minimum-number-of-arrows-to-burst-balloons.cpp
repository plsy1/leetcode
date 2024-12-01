class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) return 0;
    sort(points.begin(), points.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });
    int cur = points[0][1];
    int res = 1;
    for (int i = 1; i != points.size(); ++i) {
      if (cur < points[i][0]) {
        ++res;
        cur = points[i][1];
      }
    }
    return res;
  }
};
