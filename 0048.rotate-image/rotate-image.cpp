class Solution {
public:
void rotate(vector<vector<int> >& matrix) {
    int temp;

    for (int x = 0, y = matrix[0].size() - 1; x < y; x++, y--) {
        for (int s = x, e = y; s < y; s++, e--) {
            temp = matrix[x][s];
            matrix[x][s] = matrix[e][x];
            matrix[e][x] = matrix[y][e];
            matrix[y][e] = matrix[s][y];
            matrix[s][y] = temp;
        }
    }
}
};
