class Solution {
 public:
  string rankTeams(vector<string>& votes) {
    vector<vector<int>> dw(27, vector<int>(27, 0));
    string res;
    for (auto p : votes) {
      for (int i = 0; i < p.length(); i++) {
        dw[p[i] - 'A'][i]++;
        dw[p[i] - 'A'].back() = 26 - (p[i] - 'A');
      }
    }
    sort(dw.begin(), dw.end(), greater<vector<int>>());

    for (int i = 0; i < dw.size(); i++) {
      if (dw[i].back() != 0) res.push_back(26 - (dw[i].back() - 'A'));
    }
    return res;
  }
};
