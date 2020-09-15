class Solution {
 public:
  int calculate(string s) {
    int x = 1, y = 0;

    if (s.size() == 0) return x + y;
    for (auto c : s) {
      if (c == 'A') {
        x *= 2;
        x += y;
      } else if (c == 'B') {
        y *= 2;
        y += x;
      }
    }
    return x + y;
  }
};

class Solution {
 public:
  int calculate(string s) { return 1 << s.size(); }
};
