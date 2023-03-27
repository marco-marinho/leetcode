class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int first = rob(nums, 0, nums.size() - 1);
        int second = rob(nums, 1, nums.size());
        return max(first, second);
    }
    int rob(vector<int>& nums, int start, int end) {
        int taps[3] = {0};
        for (int i = start; i < end; i++){
            int buff = max(taps[2], taps[1]) + nums[i];
            taps[2] = taps[1];
            taps[1] = taps[0];
            taps[0] = buff;
        }
        return max(taps[0], taps[1]);
    }
};
