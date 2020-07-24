class Solution {
public:
vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > res;

    f(nums, res, 0, nums.size() - 1);
    return res;
}

void f(vector<int>& nums, vector<vector<int> >& res, int begin, int end) {
    if (begin == end) res.push_back(nums);

    unordered_set<int> uniq;

    for (int i = begin; i <= end; ++i) {
        if (uniq.count(nums[i])) continue;
        swap(nums[begin], nums[i]);
        f(nums, res, begin + 1, end);
        swap(nums[begin], nums[i]);
        uniq.insert(nums[i]);
    }
}
};
