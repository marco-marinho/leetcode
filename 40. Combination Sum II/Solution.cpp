class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> available;
        for (auto c : candidates){
            if(!available[c]) available[c] = 1;
            else available[c] += 1;
        }
        vector<vector<int>> solutions;
        vector<int> current;
        backTrack(0, target, 0, available, current, solutions);
        return solutions;
    }

    void backTrack(int sum, int target, int largest, unordered_map<int, int> &available, vector<int> &current, vector<vector<int>> &solutions){
        if (sum == target){
            solutions.push_back(current);
            return;
        }
        if (sum > target) return;
        for(auto [num, count] : available){
            if (num < largest || count < 1) continue;
            current.emplace_back(num);
            available[num] -= 1;
            backTrack(sum + num, target, max(num, largest), available, current, solutions);
            current.pop_back();
            available[num] += 1;
        }
    }
};
