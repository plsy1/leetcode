class Solution {
 public:
  int maxProductPath(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    long mini[16][16], maxi[16][16];
    int mod = 1e9 + 7;
    mini[0][0] = maxi[0][0] = grid[0][0];
    for (int i = 1; i != m; ++i)
      mini[i][0] = maxi[i][0] = mini[i - 1][0] * grid[i][0];
    for (int i = 1; i != n; ++i)
      mini[0][i] = maxi[0][i] = mini[0][i - 1] * grid[0][i];
    for (int i = 1; i != m; ++i)
      for (int j = 1; j != n; ++j) {
        mini[i][j] =
            min(mini[i][j - 1] * grid[i][j], mini[i - 1][j] * grid[i][j]);
        mini[i][j] = min(mini[i][j], maxi[i][j - 1] * grid[i][j]);
        mini[i][j] = min(mini[i][j], maxi[i - 1][j] * grid[i][j]);
        maxi[i][j] =
            max(maxi[i][j - 1] * grid[i][j], maxi[i - 1][j] * grid[i][j]);
        maxi[i][j] = max(maxi[i][j], mini[i][j - 1] * grid[i][j]);
        maxi[i][j] = max(maxi[i][j], mini[i - 1][j] * grid[i][j]);
      }
    return maxi[m - 1][n - 1] >= 0 ? maxi[m - 1][n - 1] % mod : -1;
  }
};
