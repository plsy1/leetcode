class Solution {
 public:
  int lengthOfLastWord(string s) {
    if (s.empty()) return 0;
    int pos = s.find_last_of(' ');
    while (pos == s.length() - 1) {
      if (s.empty()) return 0;
      s.erase(pos);
      pos = s.find_last_of(' ');
    }
    return s.length() - pos - 1;
  }
};
