class Solution {
public:
string addBinary(string a, string b) {
    int m = a.size();
    int n = b.size();

    while (m < n) {
        a = '0' + a; ++m;
    }
    while (n < m) {
        b = '0' + b; ++n
    }
    int flag = 0;

    for (int i = m - 1; i >= 0; --i) {
        int temp = a[i] - '0' + b[i] - '0' + flag;
        a[i] = temp % 2 + '0';
        flag = temp / 2;
    }
    if (flag > 0) a = '1' + a;

    return a;
} // addBinary

};
