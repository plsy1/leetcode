class Solution {
 public:
  int longestMountain(vector<int>& A) {
    if (A.size() < 3) return {};
    int len = A.size();
    int res = 0;
    for (int i = 1; i != len - 1; ++i) {
      if (A[i] <= A[i - 1] || A[i] <= A[i + 1]) continue;
      int tmp = 3;
      for (int j = i - 1; j > 0; --j) {
        if (A[j] <= A[j - 1]) break;
        ++tmp;
      }
      for (int j = i + 1; j != len - 1; ++j) {
        if (A[j] <= A[j + 1]) break;
        ++tmp;
      }
      res = max(res, tmp);
    }
    return res;
  }
};
