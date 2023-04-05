class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long res = 0;
        long long acc = 0;

        for (int i = 0; i < nums.size(); ++i) {
            acc += nums[i];
            res = max(res, (acc + i) / (i + 1));
        }

        return res;
    }
};
