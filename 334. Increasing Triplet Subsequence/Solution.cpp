class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = nums[0];
        int second = INT_MAX;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] < first) {
                first = nums[i];
            }
            else if(nums[i] > first && nums[i] < second){
                second = nums[i];
            }
            else if (nums[i] > second) return true;
        }
        return false;
    }
};
