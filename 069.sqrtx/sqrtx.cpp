#include <iostream>
using namespace std;
int mySqrt(int x) {
    int y = x;

    while (y * y > x)
        y = (y + x / y) / 2;
    return y;
}

int main(int argc, char const * argv[]) {
    int res = mySqrt(7);

    cout << res;
    return 0;
}
