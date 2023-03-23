class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output{{}};
        int count = 0;
        for (int i = 0;  i < nums.size(); i++){
            auto len = output.size();
            if (i >= 1 && nums[i] == nums[i - 1]) count++;
            else count = 0;
            for (int j = 0; j < len; j++){
                auto curr = output[j];
                if (count > 0) if (curr.size() < count  || curr[curr.size() - count] != nums[i]) continue;
                curr.push_back(nums[i]);
                output.push_back(curr);
            }
        }
        return output;
    }
};
