class Solution {
public:
vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > res;
    vector<int> cur;

    sort(candidates.rbegin(), candidates.rend());
    coin(candidates, target, res, cur, 0);
    return res;
}


void coin(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int> cur, int idx) {
    if (target == 0) {
        res.push_back(cur);
        return;
    }
    if (idx == candidates.size() || target < 0) return;
    int candidate = candidates[idx];

    for (int i = target / candidates[idx]; i > 0; --i) {
        cur.push_back(candidates[idx]);
    }
    for (int j = target / candidates[idx]; j >= 0; --j) {
        coin(candidates, target - candidates[idx] * j, res, cur, idx + 1);
        if (j > 0) cur.pop_back();
    }
}
};
