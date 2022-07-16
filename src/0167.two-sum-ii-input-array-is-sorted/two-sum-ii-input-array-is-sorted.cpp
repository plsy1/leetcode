class Solution {
public:
vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < numbers.size(); i++) {
        if (map.count(target - numbers[i]) > 0) {
            return { map[target - numbers[i]], i + 1 };
        }
        map[numbers[i]] = i + 1;
    }
    return vector<int>();
}
};
