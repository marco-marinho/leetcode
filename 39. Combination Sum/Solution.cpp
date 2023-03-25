class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> solutions;
        vector<int> nums;
        backTrack(0, target, nums, candidates, solutions);
        return solutions;
    }
    void backTrack(int sum, int target, vector<int> &nums, vector<int>&candidates, vector<vector<int>> &solutions){
        if (sum == target){
            solutions.push_back(nums);
            return;
        }
        if (sum > target) return;
        for (auto candidate : candidates){
            if (nums.size() > 0 && nums.back() < candidate) continue;
            nums.emplace_back(candidate);
            backTrack(sum + candidate, target, nums, candidates, solutions);
            nums.pop_back();
        }
    }
};
