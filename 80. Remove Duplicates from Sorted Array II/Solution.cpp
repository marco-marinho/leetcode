class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insert_idx = 1;
        int last_val = nums[0];
        int rep_count = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > last_val){
                nums[insert_idx] = nums[i];
                last_val = nums[i];
                insert_idx++;
                rep_count = 1;
            }
            else if (nums[i] == last_val){
                rep_count++;
                if (rep_count < 3) {
                    nums[insert_idx] = nums[i];
                    insert_idx++;
                }
            }
        }
        return insert_idx;
    }
};