class Solution {
 public:
  int matrixScore(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    int res = m * (1 << (n - 1));

    for (int j = 1; j != n; ++j) {
      int cnt = 0;
      for (int i = 0; i < m; ++i) {
        if (A[i][0])
          cnt += A[i][j];
        else
          cnt += (1 - A[i][j]);
      }
      res += max(cnt, m - cnt) * (1 << (n - j - 1));
    }
    return res;
  }
};