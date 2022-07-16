class Solution {
 public:
  bool judgeCircle(string moves) {
    unordered_map<char, int> map;
    for (auto c : moves) ++map[c];
    if (map['L'] == map['R'] && map['U'] == map['D']) return true;
    return false;
  }
};
