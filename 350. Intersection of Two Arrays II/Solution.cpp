class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums;
        vector<int> output;
        for (auto n : nums1){
            if (nums[n]) nums[n] += 1;
            else nums[n] = 1;
        }
        for (auto n : nums2){
            if (nums[n] && nums[n] > 0){
                output.push_back(n);
                nums[n] -= 1;
            }
        }
        return output;
    }
};
