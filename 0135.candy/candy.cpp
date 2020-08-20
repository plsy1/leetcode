class Solution {
 public:
  int candy(vector<int>& ratings) {
    int len = ratings.size();
    vector<int> left(len, 1);
    vector<int> right(len, 1);

    for (int i = 1; i != len; ++i) {
      if (ratings[i] > ratings[i - 1]) left[i] += left[i - 1];
    }
    int count = left.back();
    for (int i = len - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) right[i] += right[i + 1];
      count += max(left[i], right[i]);
    }
    return count;
  }
};
