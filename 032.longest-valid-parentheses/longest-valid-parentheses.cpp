class Solution {
public:
int longestValidParentheses(string s) {
    stack<int> stack;

    stack.push(-1);
    int count = 0;
    int max = 0;

    for (char w : s) {
        if (w == '(')
            stack.push(count);
        else {
            stack.pop();
            if (stack.empty())
                stack.push(count);
            else
                max = max > (count - stack.top()) ? max : (count - stack.top());
        }
        ++count;
    }
    return max;
} // longestValidParentheses
};
