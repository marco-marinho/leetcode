class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            if (i == nums.size() - 1) return true;
            int curr = nums[i];
            if (curr == 0) return false;
            int max = 0;
            int next = 0;
            for (int j = 1; j <= curr; j++){
                if (i + j >= nums.size()) return true;
                if (j + nums[i + j] >= max){
                    max = nums[i + j] + j;
                    next = i + j;
                }
            }
            i = next;
        }
        return true;
    }
};
