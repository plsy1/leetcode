#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
  int length = nums.size();
  int i = 0;
  while(i < length) {
    if(nums[i] == val) {
      nums[i] = nums[length-1];
      --length;
    }
    else ++i;
  }
  return length;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {5,8,7,6,5,9,1,3,2};
  int p = removeElement(nums,5);
  cout << p;
  return 0;
}
