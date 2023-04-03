class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if ((left == 0) || (right == 0)) return 0;
        if ((int) log2(left) != (int) log2(right)) return 0;
        int shift = 0;
        while (left != right){
            left >>= 1;
            right >>= 1;
            shift += 1;
        }
        return left << shift;
    }
};
