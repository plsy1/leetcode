class Solution {
public:
static constexpr int nums[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
int m, n;
int longestIncreasingPath(vector<vector<int> >& matrix) {
    m = matrix.size();
    if (m == 0 || matrix[0].size() == 0) return 0;
    n = matrix[0].size();
    int res = 0;
    vector<vector<int> > mem(m, vector<int>(n, 0));

    for (int i = 0; i != m; ++i) {
        for (int j = 0; j != n; ++j) {
            res = max(res, dfs(matrix, i, j, mem));
        }
    }
    return res;
}

int dfs(vector<vector<int> >& matrix, int i, int j, vector<vector<int> >& mem) {
    if (mem[i][j] != 0) return mem[i][j];
    ++mem[i][j];

    for (int s = 0; s < 4; ++s) {
        int tempRow = i + nums[s][0], tempCol = j + nums[s][1];
        if (tempRow >= 0 && tempRow < m && tempCol >= 0 && tempCol < n && matrix[tempRow][tempCol] > matrix[i][j]) {
            mem[i][j] = max(mem[i][j], dfs(matrix, tempRow, tempCol, mem) + 1);
        }
    }
    return mem[i][j];
}
};
