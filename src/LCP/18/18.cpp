class Solution {
 public:
  int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
    sort(drinks.begin(), drinks.end());
    sort(staple.begin(), staple.end());
    int res = 0, tmp = 0, mod = 1e9 + 7;
    int dmax;
    for (int i = 0; i != staple.size() && staple[i] < x; ++i) {
      dmax = x - staple[i];
      tmp = upper_bound(drinks.begin(), drinks.end(), dmax) - drinks.begin();
      res += tmp;
      res %= mod;
    }
    return res;
  }
};
