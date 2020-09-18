class Solution {
 public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    this->edges = edges;
    len = edges.size();
    father.resize(len + 1);
    unordered_map<int, int> degree;
    for (auto v : edges) ++degree[v[1]];
    for (int i = len - 1; i >= 0; --i)
      if (degree[edges[i][1]] == 2)
        if (isGraph(i)) return edges[i];
    for (int i = len - 1; i >= 0; --i)
      if (degree[edges[i][1]] == 1)
        if (isGraph(i)) return edges[i];

    return {};
  }

 private:
  int len;
  vector<int> father;
  vector<vector<int>> edges;
  int find(int n) { return father[n] == n ? n : father[n] = find(father[n]); }

  bool isGraph(int jump) {
    for (int i = 1; i <= len; ++i) father[i] = i;

    int cnt = len;
    for (int i = 0; i < len; ++i) {
      if (i == jump) continue;
      int fx = find(edges[i][0]), fy = find(edges[i][1]);
      if (fx != fy) {
        --cnt;
        father[fx] = fy;
      }
    }
    return cnt == 1;
  }
};
