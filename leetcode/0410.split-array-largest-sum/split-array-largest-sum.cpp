class Solution {
public:
int splitArray(vector<int>& nums, int m) {
    long l = nums[0], h = 0;

    for (auto n : nums) {
        l =  l > n ? l : n;
        h += n;
    }

    while (l < h) {
        long mid = l - (l - h) / 2;
        long temp = 0;
        int cnt = 1;
        for (auto n : nums) {
            temp += n;
            if (temp > mid) {
                temp = n;
                ++cnt;
            }
        }
        if (cnt > m)
            l = mid + 1;
        else
            h = mid;
    }
    return l;
} // splitArray
};
