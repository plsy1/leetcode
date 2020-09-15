class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    int col = matrix.size(), row = matrix[0].size();
    vector<int> heights(row);
    int res = 0;

    for (int i = 0; i < col; ++i) {
      for (int j = 0; j < row; ++j) {
        if (matrix[i][j] == '1')
          ++heights[j];
        else
          heights[j] = 0;
      }
      res = max(res, largestRectangleArea(heights));
    }
    return res;
  }

  int largestRectangleArea(vector<int>& heights) {
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
