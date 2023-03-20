class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int p1 = 0;
        int p2 = 0;
        int prod = nums[p1];
        while (p1 < nums.size() && p2 < nums.size()){
            if (prod < k) {
                count += p1 - p2 + 1;
                p1++;
                if (p1 < nums.size()) prod *= nums[p1];
            }
            else {
                if (p2 < p1) {
                    if (p2 < nums.size()) prod /= nums[p2];
                    p2++;
                }
                else {
                    p1++;
                    if (p1 < nums.size()) prod *= nums[p1];
                }
            }
        }
        return count;
    }
};