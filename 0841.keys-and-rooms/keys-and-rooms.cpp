class Solution {
 public:
  unordered_set<int> res;
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    dfs(rooms, 0);
    return res.size() == rooms.size();
  }

  void dfs(vector<vector<int>>& rooms, int idx) {
    res.insert(idx);
    for (auto i : rooms[idx]) {
      if (!res.count(i)) dfs(rooms, i);
    }
  }
};
