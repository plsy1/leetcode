class Solution {
public:
int search(vector<int>& nums, int target) {
    int len = nums.size();

    if (len == 0) {
        return -1;
    }
    int left = 0;
    int right = len - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] >= nums[left]) {// mid in left path
            if (target > nums[mid] || target < nums[left]) {// target > left to mid or target in left path
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else { // mid in right path
            if (target < nums[mid] || target >= nums[left]) {// target in left path
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return -1;
} // search
};
