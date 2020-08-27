class Solution {
public:
bool isValidSudoku(vector<vector<char> >& board) {
    int row[9][9]{};
    int col[9][9]{};
    int box[9][9]{};

    for (int i = 0; i != 9; ++i) {
        for (int j = 0; j != 9; ++j) {
            if (board[i][j] == '.') continue;
            int cur = board[i][j] - '1'; // return 1-9
            if (row[i][cur] || col[j][cur] || box[i / 3 * 3 + j / 3][cur]) return false;
            row[i][cur] = 1;
            col[j][cur] = 1;
            box[i / 3 * 3 + j / 3][cur] = 1;
        }
    }
    return true;
}
};
