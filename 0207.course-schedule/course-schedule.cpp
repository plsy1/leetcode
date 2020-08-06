class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    map<int, set<int>> adjcent;
    vector<int> indegree(numCourses);
    int a, b;
    for (auto &edge : prerequisites) {
      a = edge[0];
      b = edge[1];
      adjcent[b].insert(a);
      ++indegree[a];
    }
    int count = 0;
    queue<int> todo;
    for (int i = 0; i < numCourses; ++i)
      if (!indegree[i]) todo.push(i);
    while (!todo.empty()) {
      auto v = todo.front();
      todo.pop();
      ++count;
      auto &adjs = adjcent[v];
      for (auto adj : adjs) {
        --indegree[adj];
        if (!indegree[adj]) todo.push(adj);
      }
    }
    return count == numCourses;
  }
};
