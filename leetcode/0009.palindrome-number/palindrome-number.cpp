class Solution {
public:
bool isPalindrome(int x) {
    if (x < 0)
        return false;
    int copy = x;
    int length_get = 1;

    while (copy >= 10) {
        length_get *= 10;
        copy /= 10;
    }
    while (x != 0) {
        if (x % 10 != x / length_get)
            return false;
        x = x % length_get / 10;
        length_get /= 100;
    }
    return true;
}
};
