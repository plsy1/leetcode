class Solution {
public:
bool containsDuplicate(vector<int>& nums) {
    map<int, int> res;

    for (int i = 0; i != nums.size(); ++i) {
        res[nums[i]]++;
    }
    for (int i = 0; i != nums.size(); ++i) {
        if (res[nums[i]] > 1)
            return true;
    }
    return false;
}
};
