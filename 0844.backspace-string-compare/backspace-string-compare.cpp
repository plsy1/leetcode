class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    stack<int> a, b;
    for (auto c : S) {
      if (c != '#')
        a.push(c);
      else if (!a.empty())
        a.pop();
    }
    for (auto c : T) {
      if (c != '#')
        b.push(c);
      else if (!b.empty())
        b.pop();
    }
    return a == b;
  }
};
