class Solution {
    public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        auto digits = (int)log10(x) + 1;
        if (digits == 1) return true;
        auto divisor = 1;
        for (auto i = 1; i < digits; i++) divisor *= 10;
        while(divisor > 1){
            auto first = x / divisor;
            auto second = x % 10;
            if (first != second) return false;
            x = (x - (first*divisor)) / 10;
            divisor /= 100;
        }
        return true;
    }
};