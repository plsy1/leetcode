class Solution {
public:
vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> stack;
    int count = T.size();
    vector<int> res(count, 0);

    for (int i = 0; i != count - 1; ++i) {
        while (!stack.empty() && T[i] >= T[stack.top()]) {
            res[stack.top()] = i - stack.top();
            stack.pop();
        }

        stack.push(i);
    }
    return res;
}
};
