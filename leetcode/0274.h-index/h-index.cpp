class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int len = citations.size();
    if (!len) return 0;
    sort(citations.begin(), citations.end());
    int h = len;
    for (int i = 0; i != len; ++i)
      if (citations[i] < h) --h;
    return h;
  }
};
