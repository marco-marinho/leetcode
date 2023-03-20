class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = INT_MAX;
        int p1 = 0;
        int p2 = 0;
        int sum = nums[p1];
        while(p1 < nums.size()){
            if (sum >= target){
                if (p1 - p2 + 1 < min) min = p1 - p2 + 1;
                if (p1 > p2){
                    sum -= nums[p2++];
                }
                else{
                    p1++;
                    if (p1 < nums.size()) sum += nums[p1];
                }
            }
            else {
                p1++;
                if (p1 < nums.size()) sum += nums[p1];
            }
        }
        if (min == INT_MAX) return 0;
        return min;
    }
};