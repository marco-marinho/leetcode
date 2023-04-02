class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n-1;
        int n3 = n / 3;
        int rest = n % 3;
        if (rest == 0) return (int) pow(3, n3);
        if (rest == 1) return (int) 4 * pow(3, n3 - 1);
        return rest * (int) pow(3, n3);
    }
};
