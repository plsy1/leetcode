class Solution {
public:
int findBestValue(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int pre = 0;

    for (int i = 0; i != arr.size(); ++i) {
        int k = arr.size() - i;
        int d = pre + arr[i] * k - target;
        if (d >= 0) return arr[i] - (d + k / 2) / k;
        pre += arr[i];
    }
    return arr[arr.size() - 1];
}
};
/*
 * 参考https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target/solution/zui-you-jie-fa-onlogn-by-java_lee/
 */
