class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    for (int i = 0; i != grid.size(); ++i)
      for (int j = 0; j != grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          ++res;
          dfs(i, j, grid);
        }
      }
    return res;
  }

 private:
  void dfs(int i, int j, vector<vector<char>>& grid) {
    if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() ||
        grid[i][j] == '0')
      return;
    grid[i][j] = '0';
    vector<vector<int>> move{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int t = 0; t != 4; ++t) {
      dfs(i + move[t][0], j + move[t][1], grid);
    }
  }
};
