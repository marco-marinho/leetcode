class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxval = INT_MIN;
        int last = 0;
        for (int i = 0; i < nums.size(); i++){
            last = max(nums[i], last + nums[i]);
            if (last > maxval) maxval = last;
        }
        return maxval;
    }
};
