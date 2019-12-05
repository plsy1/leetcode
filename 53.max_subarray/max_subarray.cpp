#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int max3(int a, int b, int c);
int max_croos(vector<int> nums,int left,int right,int mid);
int partition(vector<int> nums, int left, int right);

int max3(int a, int b, int c) {
	return max(a, max(b, c));
}
int max_croos(vector<int> nums, int left, int right, int mid)
{
	int lmax = INT_MIN;int rmax = INT_MIN;
	int sum_l = 0; int sum_r = 0;
	for (int i = mid; i >= left; --i)
	{
		sum_l += nums[i];
		if (sum_l > lmax)
			lmax = sum_l;
	}
	for (int j = mid+1; j <= right;++j)
	{
		sum_r += nums[j];
		if (sum_r > rmax)
			rmax = sum_r;
	}
	return lmax + rmax;
}
int partition(vector<int> nums, int left, int right)
{
	if (left == right)
		return nums[left];
	int mid = (right+left) / 2;
	return max3(partition(nums, left, mid), partition(nums, mid + 1, right), max_croos(nums, left, right, mid));
}
int main()
{
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int i = partition(nums, 0, 8);
	cout << i << endl;
	return 0;
}

