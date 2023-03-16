class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }
        int pivot = findPivot(nums);
        if (pivot != -1) {
            std::rotate(nums.begin(), nums.begin() + pivot, nums.end());
        }
        else {
            pivot = 0;
        }
        int L = 0;
        int R = nums.size() - 1;
        while(L <= R){
            int half = (L + R) / 2;
            if (nums[half] == target) return (half + pivot) % nums.size();
            if (nums[half] < target) {
                L = (half + 1);
            }
            else {
                R = (half - 1);
            }
        }
        return -1;
    }

    int findPivot(vector<int>& nums)
    {
        for (int idx = 0; idx < nums.size() - 1; idx++) {
         if (nums[idx] > nums[idx + 1]) return idx + 1;
        }
        return -1;
    }

};