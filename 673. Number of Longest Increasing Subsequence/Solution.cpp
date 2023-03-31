typedef pair<int, int> ipair;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<ipair> memory(nums.size(), {-1, -1});
        int maximum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            auto [val, count] = lenIS(i, nums, memory);
            if (val > maximum){
                maximum = val;
                ans = count;
            }
            else if (val == maximum) ans += count;
        }
        return ans;
    }
    ipair lenIS(int idx, vector<int>& nums, vector<ipair> &memory){
        if (idx == nums.size() - 1) return {1, 1};
        if(memory[idx].first != -1) return memory[idx];
        int maximum = 1; int count = 1;
        for (int i = idx + 1; i < nums.size(); i++){
            if (nums[idx] < nums[i]){
                auto [tval, tcount] = lenIS(i, nums, memory);
                tval += 1;
                if (tval > maximum){
                    maximum = tval;
                    count = tcount;
                }
                else if (tval == maximum) count += tcount;
            }
        }
        return memory[idx] = {maximum, count};
    }


};
