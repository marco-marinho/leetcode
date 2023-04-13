class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        bool negative = (dividend < 0 != divisor < 0);
        uint32_t udividend = abs(dividend);
        uint32_t udivisor = abs(divisor);
        uint32_t res = 0;
        while(udividend >= udivisor){
            uint32_t q = 0;
            while(udividend > (udivisor << (q + 1))){
                q++;
            }
            res += 1<<q;
            udividend -= udivisor<<q;
        }
        if (res == 1<<31 && !negative) return INT_MAX;
        if (negative) return -res;
        return res;
    }
};
