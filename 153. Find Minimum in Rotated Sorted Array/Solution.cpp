class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int L = 0;
        int R = nums.size() - 1;
        while (L <= R){
            if (R - L == 1) return min(nums[R], nums[L]);
            int half = (L + R) / 2;

            if (half == 0 || half == nums.size() - 1) return nums[half];
            if (nums[half - 1] > nums[half] && nums[half] < nums[half] + 1) return nums[half];
            //Right is sorted, discard
            if (nums[half] < nums[R]) {
                R = half - 1;
            }
            else {
                L = half + 1;
            }
        }
        return -1;
    }
};