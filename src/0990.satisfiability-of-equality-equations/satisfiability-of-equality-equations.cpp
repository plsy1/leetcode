class Solution {
public:
int parents[26];
bool equationsPossible(vector<string>& equations) {
    if (equations.empty()) return true;
    for (int i = 0; i < 26; ++i) {
        parents[i] = i;
    }
    for (int i = 0; i < equations.size(); ++i) {
        if (equations[i][1] == '=') {
            int x = find(equations[i][0] - 'a');
            int y = find(equations[i][3] - 'a');
            if (x != y) parents[x] = y;
        }
    }
    for (int i = 0; i < equations.size(); ++i) {
        if (equations[i][1] == '!') {
            int x = find(equations[i][0] - 'a');
            int y = find(equations[i][3] - 'a');
            if (x == y) return false;
        }
    }
    return true;
} // equationsPossible

int find(int i) {
    while (i != parents[i]) {
        parents[i] = parents[parents[i]];
        i = parents[i];
    }
    return i;
}
};
