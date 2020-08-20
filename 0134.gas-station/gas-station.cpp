class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size(), sum = 0, left = INT_MAX, sub;
    for (int i = 0; i != len; ++i) {
      sum += gas[i] - cost[i];
      if (sum < left) {
        sub = i;
        left = sum;
      }
    }
    return sum >= 0 ? (sub + 1) % len : -1;
  }
};
