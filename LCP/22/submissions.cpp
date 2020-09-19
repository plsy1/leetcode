class Solution {
 public:
  int paintingPlan(int n, int k) {
    int res = 0;
    if (k == n * n) return 1;
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j)
        if ((i + j) * n - i * j == k) res += C(n, i) * C(n, j);
    return res;
  }

  int C(int n, int m) {
    int up = 1, down = 1, tmp = m;
    while (tmp--) {
      up *= n--;
      down *= m--;
    }
    return up / down;
  }
};
