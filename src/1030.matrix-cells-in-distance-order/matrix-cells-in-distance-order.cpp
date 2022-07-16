class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
      vector<vector<int>> res;
      for(int i = 0;i < R;++i)
        for(int j = 0;j < C;++j)
          res.push_back({i,j});
      sort(res.begin(),res.end(),
      [r0,c0](auto& m, auto& n) {
        return  abs(r0 - m[0]) + abs(c0 - m[1]) < abs(r0 - n[0]) + abs(c0 - n[1]);
      });
      return res;
    }
};
