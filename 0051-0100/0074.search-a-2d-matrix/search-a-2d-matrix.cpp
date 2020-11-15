class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return false;
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m * n - 1;

    while (l < r) {
      int mid = l - (l - r) / 2;
      if (matrix[mid / n][mid % n] >= target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    if (matrix[l / n][l % n] == target) return true;
    return false;
  }
};
