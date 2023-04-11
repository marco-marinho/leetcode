class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = {0};
        for(const auto n : nums){
            counts[n]++;
        }
        for (int i = 0; i < nums.size(); i++){
            if (counts[0] > 0){
                nums[i] = 0;
                counts[0]--;
            }
            else if (counts[1] > 0){
                nums[i] = 1;
                counts[1]--;
            }
            else nums[i] = 2;
        }
    }
};
