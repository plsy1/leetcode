class Solution {
 public:
  int largestRectangleArea(vector<int> &heights) {
    vector<int> s;
    int res = 0;
    heights.push_back(0);
    for (int i = 0; i != heights.size(); ++i) {
      while (!s.empty() && heights[s.back()] >= heights[i]) {
        int h = heights[s.back()];
        s.pop_back();
        if (s.empty())
          res = max(res, i * h);
        else
          res = max(res, (i - s.back() - 1) * h);
      }
      s.push_back(i);
    }
    return res;
  }
};
