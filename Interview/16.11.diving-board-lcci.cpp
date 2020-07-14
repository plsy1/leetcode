class Solution {
public:
vector<int> divingBoard(int shorter, int longer, int k) {
    vector<int> res;

    if (k == 0) return res;
    if (shorter == longer) {
        res.push_back(shorter * k);
        return res;
    }
    int sum = shorter * k;
    int m = longer - shorter;

    res.push_back(sum);
    for (int i = 0; i != k; ++i) {
        sum += m;
        res.push_back(sum);
    }
    return res;
}
};
