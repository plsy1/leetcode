// Double pointer
class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
	// Sort
	int len = nums.size();

	sort(nums[0], nums[len - 1]);

	int ClosestSum = INT_MAX;

	for (int i = 0; i != nums.size() - 2; ++i) {
	    int l = i + 1, r = nums.size() - 1;

	    while (l < r) {
		int threeSum = nums[l] + nums[r] + nums[i];

		if (abs(threeSum - target) < abs(ClosestSum - target))
		    ClosestSum = threeSum;
		if (threeSum > target)
		    r--;
		else if (threeSum < target)
		    l++;
		else
		    return target;
	    }
	}
	return ClosestSum;
    }
};
