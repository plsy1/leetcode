class Solution {
 public:
  vector<int> splitIntoFibonacci(string S) {
    backtrack(S, 0);
    return res;
  }

 private:
  vector<int> res, cur;

  bool backtrack(string& S, int left) {
    if (left == S.size()) {
      if (cur.size() >= 3) {
        res = cur;
        return true;
      }
      return false;
    }

    for (int i = left; i != S.size(); ++i) {
      string str = S.substr(left, i - left + 1);
      if ((str.size() > 1 && str[0] == '0') || (str.size() > 10) ||
          (str.size() == 10 && str >= to_string(INT_MAX)))
        continue;
      long num = stoi(str);
      bool isValid = (cur.size() <= 1) ||
                     ((long)cur.back() + (long)cur[cur.size() - 2] == num);
      if (isValid) {
        cur.push_back(num);
        if (backtrack(S, i + 1)) return true;
        cur.pop_back();
      }
    }
    return false;
  }
};