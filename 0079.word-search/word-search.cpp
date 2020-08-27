class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i != board.size(); ++i)
      for (int j = 0; j != board[0].size(); ++j)
        if (dfs(board, word, i, j, 0)) return true;
    return false;
  }
  bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
    if (board[i][j] != word[idx]) return false;
    if (idx == word.size() - 1) return true;
    board[i][j] = '.';
    if ((i - 1 >= 0 && dfs(board, word, i - 1, j, idx + 1)) ||
        (j + 1 <= board[0].size() - 1 && dfs(board, word, i, j + 1, idx + 1)) ||
        (i + 1 <= board.size() - 1 && dfs(board, word, i + 1, j, idx + 1)) ||
        (j - 1 >= 0 && dfs(board, word, i, j - 1, idx + 1)))
      return true;

    board[i][j] = word[idx];

    return false;
  }
};
