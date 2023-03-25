class Solution {
public:
    int reverse(int x) {
        int output = 0;
        auto digits = numDigits(x);
        auto pow = digits.pow;
        for (auto digit = 0; digit < digits.digits; digit++){
            output += (x % 10) * pow;
            x /= 10;
            pow /= 10;
        }
        return output;
    }
private:
    struct digitsRes {
        int digits;
        int pow;
    };
    digitsRes numDigits(int x) {
        int res = 0;
        int pow = 1;
        if (x < 0) x *= -1;
        while (x > 0){
            res++;
            x /= 10;
        }
        for (auto i = 0; i < res - 1; i++) pow *= 10;
        return digitsRes{.digits = res, .pow = pow};
    }

};
