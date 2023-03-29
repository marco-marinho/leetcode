class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int jumps = 0;
        for (int i = 0; i < nums.size() - 1; i++){
            start = max(start, nums[i] + i);
            if (i == end){
                end = start;
                jumps++;
            }
        }
        return jumps;
    }
};