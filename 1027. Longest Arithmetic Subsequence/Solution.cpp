class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int, int>> res(nums.size(), unordered_map<int, int>());
        int output = 0;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                int diff = nums[i] - nums[j];
                if(res[j].count(diff)) res[i][diff] = res[j][diff] + 1;
                else res[i][diff] = 2;
                output = max(output, res[i][diff]);
            }
        }
        return output;
    }
};
