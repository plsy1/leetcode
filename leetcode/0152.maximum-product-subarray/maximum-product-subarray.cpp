class Solution {
public:
int maxProduct(vector<int>& nums) {
    int len = nums.size();
    int temp = 0;
    int max_ = 1;
    int neg[len]; // 负数数组
    int s = 0; // 存放负数下标

    if (len == 0 || len == 1)
        return nums[0];
    for (int i = 0; i != len; ++i) {
        if (nums[i] < 0) {
            neg[s++] = i;
            temp++;
        }
    }
    if (temp % 2 == 0) { // 偶数个
        for (int i = 0; i != len; ++i) {
            max_ *= nums[i];
            if (nums[i] == 0 && i != len - 1)
                max_ = 1;
        }
        return max_;
    } else {
        int left_max = 1;
        int right_max = 1;
        for (int i = 0; i != neg[temp - 1]; ++i) {
            left_max *= nums[i];
        }
        for (int i = len - 1; i != neg[0]; --i) {
            right_max *= nums[i];
        }
        max_ = max(left_max, right_max);
    }
    return max_;
} // maxProduct
};
