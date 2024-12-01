class Solution {
 public:
  string countAndSay(int n) {
    string res = "1";
    int j = 1;
    while (j++ < n) {
      string cur;
      int pos = 0;
      for (int i = 0; i < res.size(); ++i) {
        if (i + 1 == res.size() || res[i] != res[i + 1]) {
          cur += (i + 1 - pos) + '0';
          cur += res[i];
          pos = i + 1;
        }
      }
      res = cur;
    }
    return res;
  }
};
