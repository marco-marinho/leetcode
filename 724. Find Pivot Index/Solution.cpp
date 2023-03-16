class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumRight = 0;
        int sumLeft = 0;
        for (auto el : nums){
            sumLeft += el;
        }
        for (int i = 0; i < nums.size(); i++) {
            sumLeft -= nums[i];
            if (sumLeft == sumRight) return i;
            sumRight += nums[i];
        }
        return -1;
    }
};
