class Solution {
public:
int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    if (divisor == 1) return dividend;
    if (divisor == -1) {
        if (dividend > INT_MIN) return -dividend;
        return INT_MAX;
    }
    long a = dividend;
    long b = divisor;
    int result = 0;

    a = ( a > 0 ? a : -a);
    b = ( b > 0 ? b : -b);

    while (a >= b) {
        long temp = b;
        int count = 1;
        while (a - temp >= temp) {
            temp = temp << 1;
            count = count << 1;
        }
        a -= temp;
        result += count;
    }
    if (dividend < 0 && divisor < 0 )
        return result;
    else if (dividend > 0 && divisor > 0)
        return result;
    else
        return -result;
} // divide
};
