class Solution {
 public:
  string reverseWords(string s) {
    s += ' ';
    string res;
    string temp;
    if (s.empty()) return "";
    for (int i = 0; i != s.size(); ++i) {
      if (s[i] == ' ') {
        for (int i = temp.size() - 1; i >= 0; --i) res += temp[i];

        res += " ";
        temp = "";
      } else {
        temp += s[i];
      }
    }
    res = res.substr(0, res.size() - 1);
    return res;
  }
};

//随便写写得了，没什么好说的
