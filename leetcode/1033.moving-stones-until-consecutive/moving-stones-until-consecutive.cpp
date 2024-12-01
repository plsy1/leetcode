class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {

        if(a > b) swap(a,b);
        if(a > c) swap(a,c);
        if(b > c) swap(b,c);
        int max = c - a - 2,min = 0;

        if(b - a == 2 || c - b == 2) return {1,max};
        if(b - a != 1) ++min;
        if(c- b != 1) ++min;

        return {min,max};

    }
};
