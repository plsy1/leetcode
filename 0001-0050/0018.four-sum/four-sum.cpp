class Solution {
public:
vector<vector<int> > fourSum(vector<int>& nums, int target) {
    int len = nums.size();
    int a, b, c, d;
    vector<vector<int> > res;
    int sum;

    if (len < 4)
        return res;
    sort(nums.begin(), nums.end());
    if (nums[0] + nums[1] + nums[2] + nums[3] > target)
        return res;
    if (nums[len - 1] + nums[len - 4] + nums[len - 2] + nums[len - 3]  < target)
        return res;
    for (a = 0; a <= len - 4; ++a) {
        if (a > 0 && nums[a] == nums[a - 1]) continue;
        for (b = a + 1; b <= len - 3; ++b) {
            if (b > a + 1 && nums[b] == nums[b - 1]) continue;
            c = b + 1, d = len - 1;
            while (d > c) {
                sum = nums[a] + nums[b] + nums[c] + nums[d];
                if (sum < target)
                    ++c;
                else if (sum > target)
                    --d;
                else {
                    res.push_back({ nums[a], nums[b], nums[c], nums[d] });
                    while (c < d && nums[c + 1] == nums[c])
                        ++c;
                    while (c < d && nums[d - 1] == nums[d])
                        --d;
                    ++c;
                    --d;
                }
            }
        }
    }
    return res;
} // fourSum
};
