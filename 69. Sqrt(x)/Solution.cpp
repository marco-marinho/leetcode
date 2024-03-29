class Solution {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = x;
        while(left <= right){
            long long half = left + (right - left) / 2;
            long long res = half * half;
            if (res == x) return half;
            if (res > x) right = half - 1;
            else left = half + 1;
        }
        return right;
    }
};
