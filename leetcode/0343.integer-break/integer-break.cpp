class Solution {
public:
    int integerBreak(int n) {
        assert(n >= 2);
        if(n <= 3) return n - 1;
        int res = 1;
        while(n > 4) {
            ans *= 3;
            n  -= 3;
        }
        return ans * n;
    }
};
