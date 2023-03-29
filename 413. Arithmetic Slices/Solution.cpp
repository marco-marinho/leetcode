class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int slices = 0;
        int count = 0;
        int lastDiff = INT_MAX;
        for (int i = 0; i < nums.size() - 1; i++){
            int diff = nums[i] - nums[i + 1];
            if (diff != lastDiff){
                if (count > 1){
                    slices += ((1 + count - 1)*(count - 1)) / 2;
                }
                count = 1;
                lastDiff = diff;
            }
            else count++;
        }
        if (count > 1){
            slices += ((1 + count - 1)*(count - 1)) / 2;
        }
        return slices;
    }
};
