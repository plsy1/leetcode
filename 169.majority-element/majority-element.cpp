class Solution {
public:
    int majorityElement(vector<int>& nums) {
  int len = nums.size();
  if(len == 1) return nums[0];
  map<int,int> temp;
  int majority = INT_MIN;
  for(int i = 0;i!=len;++i){
    temp[nums[i]] = 0;
  }
  for(int i = 0;i!=len;++i){
    temp[nums[i]]++;
  }
  for(int i = 0;i!=len;++i){
    if(temp[nums[i]] > len/2)
      majority = max(majority,nums[i]);
  }
  return majority;
    }
};
