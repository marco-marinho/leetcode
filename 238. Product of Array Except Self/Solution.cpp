class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        vector<int> direct(nums.size(), 1);
        vector<int> reverse(nums.size(), 1);
        int dir = 1;
        int rev = 1;
        for (int i = 0; i < nums.size() - 1; i++){
            dir *= nums[i];
            direct[i + 1] = dir;
            rev *= nums[nums.size() - 1 - i];
            reverse[nums.size() - 2 - i] = rev;
        }
        vector<int> output(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++){
            output[i] = direct[i] * reverse[i];
        }
        return output;
    }
};