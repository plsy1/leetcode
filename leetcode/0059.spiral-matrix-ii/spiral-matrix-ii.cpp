class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    if (n == 0) return {{}};
    vector<vector<int>> res(n, vector<int>(n));

    int left = 0, right = res[0].size() - 1;
    int up = 0, down = res.size() - 1;
    int num = 1;

    while (1) {
      for (int i = left; i <= right; ++i) res[up][i] = num++;
      if (++up > down) break;
      for (int i = up; i <= down; ++i) res[i][right] = num++;
      if (--right < left) break;
      for (int i = right; i >= left; --i) res[down][i] = num++;
      if (--down < up) break;
      for (int i = down; i >= up; --i) res[i][left] = num++;
      if (++left > right) break;
    }

    return res;
  }
};
