class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    int len = name.size(), idx = 0;
    for (auto c : typed) {
      if (c == name[idx])
        ++idx;
      else if (c != name[idx - 1])
        return false;
    }
    return idx == name.size();
  }
};
