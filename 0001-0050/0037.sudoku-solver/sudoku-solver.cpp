class Solution {
 public:
  vector<vector<char>> board;
  void solveSudoku(vector<vector<char>>& board) {
    this->board = board;
    backtrack(0, 0);
    board = this->board;
  }
  bool backtrack(int row, int col) {
    if (col == 9) return backtrack(row + 1, 0);
    if (row == 9) return true;
    for (int i = row; i != 9; ++i)
      for (int j = col; j != 9; ++j) {
        if (board[i][j] != '.') return backtrack(i, j + 1);
        for (char c = '1'; c <= '9'; ++c) {
          if (!isValid(i, j, c)) continue;
          board[i][j] = c;
          if (backtrack(i, j + 1)) return true;
          board[i][j] = '.';
        }
        return false;
      }
    return false;
  }

  bool isValid(int row, int col, char c) {
    for (int i = 0; i != 9; ++i) {
      if (board[row][i] == c) return false;
      if (board[i][col] == c) return false;
      if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == c)
        return false;
    }
    return true;
  }
};
