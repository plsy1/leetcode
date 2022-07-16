class Solution {
public:
int minArray(vector<int>& numbers) {
    if (numbers.size() == 1) return numbers[0];

    for (int i = 0; i != numbers.size() - 1; ++i) {
        if (numbers[i] > numbers[i + 1])
            return numbers[i + 1];
    }
    return numbers[0];

}
};
