// two pointers
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    int len = A.size();
    vector<int> res(len);
    int l = 0, r = len - 1, idx = len - 1;
    while (l <= r) {
      res[idx--] = A[l] * A[l] > A[r] * A[r] ? A[l] * A[l++] : A[r] * A[r--];
    }
    return res;
  }
};

// sort
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    for (auto& i : A) i *= i;
    sort(A.begin(), A.end());
    return A;
  }
};
