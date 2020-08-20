class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    unordered_map<int, int> money;
    money[5] = 0;
    money[10] = 0;
    money[20] = 0;
    for (auto i : bills) {
      if (i == 5)
        ++money[5];
      else if (i == 10) {
        ++money[10];
        --money[5];
      } else if (i == 20) {
        ++money[20];
        if (money[10] > 0 && money[5] > 0) {
          --money[10];
          --money[5];
        } else {
          money[5] -= 3;
        }
      }
      if (money[5] < 0) return false;
    }
    return true;
  }
};
