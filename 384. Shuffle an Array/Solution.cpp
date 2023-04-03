class Solution {
public:
    Solution(vector<int>& nums) {
        original = nums;
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> copy(original.size(), 0);
        for(int i = 0; i < copy.size(); i++){
            auto target = rand() % copy.size();
            copy[i] = original[target];
            copy[target] = original[i];
        }
        return copy;
    }
private:
    vector<int> original;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
