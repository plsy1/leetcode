class Solution {
 public:
  char findTheDifference(string s, string t) {
    unordered_map<char, int> map;
    unordered_map<char, int> map1;
    for (auto c : s) ++map[c];

    for (auto c : t) ++map1[c];

    for (auto c : t)
      if (map[c] == 0 || map[c] != map1[c]) return c;

    return ' ';
  }
};

class Solution {
 public:
  char findTheDifference(string s, string t) {
    int res = 0;
    for (auto c : s) res ^= c;
    for (auto c : t) res ^= c;

    return (char)res;
  }
};
