class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memory(nums.size(), -1);
        int maximum = 1;
        for (int i = 0; i < nums.size(); i++){
            maximum = max(maximum, lenIS(i, nums, memory));
        }
        return maximum;
    }
    int lenIS(int idx, vector<int>& nums, vector<int> &memory){
        if (idx == nums.size() - 1) return 1;
        if(memory[idx] != -1) return memory[idx];
        int maximum = 1;
        for (int i = idx + 1; i < nums.size(); i++){
            if (nums[idx] < nums[i]){
                maximum = max(maximum, 1 + lenIS(i, nums, memory));
            }
        }
        return memory[idx] = maximum;
    }
};
