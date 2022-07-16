class Solution {
public:
int findBestValue(vector<int>& arr, int target) {

    int left = target / arr.size();
    int right = INT_MIN;

    for (int s : arr) {
        right = max(right, s);
    }

    int resultVal = INT_MAX;
    int result = left;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int value = sumSet(arr, mid);
        if (resultVal > abs(value - target)) {
            resultVal = abs(value - target);
            result = mid;
        }
        if (resultVal == abs(value - target) && result > mid) result = mid;
        if (value < target) {
            left = mid + 1;
        } else if (value > target)
            right = mid - 1;
        else
            return mid;
    }
    return result;
} // findBestValue
int sumSet(vector<int> arr, int cur) {
    int sum = 0;

    for (int s : arr) {
        sum += s > cur ? cur : s;
    }
    return sum;
}
};
