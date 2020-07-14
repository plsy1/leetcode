class Solution {
public:
int sumNums(int n) {
    return (n && (n += sumNums(n - 1))) ? n : n;
}
};
