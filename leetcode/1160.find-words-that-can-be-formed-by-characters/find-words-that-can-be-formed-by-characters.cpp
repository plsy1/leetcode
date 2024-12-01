/*
map
*/
class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    int res = 0;
    unordered_map<char, int> m;
    for (auto c : chars) ++m[c];
    for (auto i : words) {
      unordered_map<char, int> tmp;
      bool flag = true;
      for (auto c : i) ++tmp[c];
      for (auto c : i) {
        if (m[c] < tmp[c]) {
          flag = false;
          break;
        }
      }
      if (flag) res += i.size();
    }
    return res;
  }
};
/*
int[26]
*/
class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    int res = 0;
    int m[26] = {0};
    for (auto c : chars) ++m[c - 'a'];
    for (auto i : words) {
      int tmp[26] = {0};
      bool flag = true;
      for (auto c : i) ++tmp[c - 'a'];
      for (auto c : i) {
        if (m[c - 'a'] < tmp[c - 'a']) {
          flag = false;
          break;
        }
      }
      if (flag) res += i.size();
    }
    return res;
  }
};
