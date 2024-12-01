class Solution {
public:
int maxScoreSightseeingPair(vector<int>& A) {
    int res = 0, mx = A[0] + 0;

    for (int i = 1; i != A.size(); ++i) {
        res = max(res, mx + A[i] - i);
        mx = max(mx, A[i] + i);
    }
    return res;
}
};
/*
 * A[i] + A[j] + i - j = (A[i] + i + A[j] - j)
 */
