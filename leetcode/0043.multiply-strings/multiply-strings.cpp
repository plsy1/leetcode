class Solution {
public:
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int s1 = num1.size();
    int s2 = num2.size();

    int * ans = new int[s1 + s2] { 0 };

    for (int i = 0; i < s1; ++i) {
        for (int j = 0; j < s2; ++j) {
            ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    for (int i = 0; i < s1 + s2; ++i) {
        if (ans[i] > 9) {
            ans[i + 1] += (ans[i] / 10);
            ans[i] %= 10;
        }
    }

    int pos = (ans[s1 + s2 - 1] == 0 ? s1 + s2 - 2 : s1 + s2 - 1);

    string res = "";

    for (; pos >= 0; --pos) {
        res += ans[pos] + '0';
    }

    return res;
} // multiply

};
