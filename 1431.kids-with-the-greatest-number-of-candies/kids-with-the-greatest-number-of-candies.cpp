class Solution {
public:
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

    vector<bool> res{};
    auto max = max_element(candies.begin(), candies.end());
    int m = *max;

    for (auto i : candies) {
        res.push_back(i + extraCandies >= m);
    }
    return res;
}
};
