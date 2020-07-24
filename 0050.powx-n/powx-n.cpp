#include <iostream>
using namespace std;

class Solution {
public:
double myPow(double x, int n) {
    if (x == 0 || n == 1) return x;
    if (n == 0) return 1;

    double res = 1;
    long cur = abs(n);

    while (cur) {
        if (cur & 1) res *= x;
        x *= x;
        cur >>= 1;
    }

    return n > 0 ? res : 1 / res;
}
};

int main(int argc, char const * argv[]) {
    Solution a;
    double foo = 2.1;

    cout << a.myPow(foo, 3);
    return 0;
}
