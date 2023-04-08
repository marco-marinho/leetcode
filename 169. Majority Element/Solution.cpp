class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int votes = 0;
        for (const auto n : nums){
            if(votes == 0){
                candidate = n;
                votes = 1;
            }
            else if(n == candidate) votes++;
            else votes--;
        }
        return candidate;
    }
};
