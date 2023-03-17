class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;
        while (L < R) {
            int half = (L + R) / 2;
            if (nums[half] > nums[half + 1]){
                R = half;
            }
            else{
                L = half + 1;
            }
        }
        return L;
    }
};