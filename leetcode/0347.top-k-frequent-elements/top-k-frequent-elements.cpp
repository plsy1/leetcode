class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int, int> map;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        queue;

    for (auto n : nums) ++map[n];
    for (auto i : map) {
      if (queue.size() == k) {
        if (i.second > queue.top().first) {
          queue.pop();
          queue.push(make_pair(i.second, i.first));
        }
      } else
        queue.push(make_pair(i.second, i.first));
    }

    while (queue.size()) {
      res.push_back(queue.top().second);
      queue.pop();
    }
    return vector<int>{res.rbegin(), res.rend()};
  }
};
