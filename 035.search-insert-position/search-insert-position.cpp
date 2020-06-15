class Solution {
public:
int searchInsert(vector<int>& nums, int target) {
    int len = nums.size();
    int left = 0;
    int right = len - 1;

    if (nums[right] < target)
        return len;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;

    }
    return left;
}
};
