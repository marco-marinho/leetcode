class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 1) return {nums};
        unordered_map<int, int> counts;
        for (auto num : nums){
            if(!counts[num]) counts[num] = 1;
            else counts[num]++;
        }
        vector<vector<int>> solutions;
        backTrack(nums.size(), {}, counts, solutions);
        return solutions;
    }

    void backTrack(int n, vector<int> current, unordered_map<int, int> &counts, vector<vector<int>> & solutions){
        if(current.size() == n){
            solutions.push_back(current);
            return;
        }
        for(auto [num, count] : counts){
            if (count < 1) continue;
            current.emplace_back(num);
            counts[num] -= 1;
            backTrack(n, current, counts, solutions);
            counts[num] += 1;
            current.pop_back();
        }
    }

};
