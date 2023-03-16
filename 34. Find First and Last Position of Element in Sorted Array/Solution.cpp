class Solution {
public:
       vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0) return vector<int>{-1, -1};
        auto first = findFirst(nums, target);
        if (first == -1) return vector<int>{-1, -1};
        auto last = findLast(nums, target);
        return vector<int>{first, last};
    }

    int findFirst(vector<int> nums, int target)
    {
        if (nums[0] == target) return 0;
        auto L = 0;
        int R = nums.size() - 1;
        while (L <= R) {
            auto half = (R + L) / 2;
            if (nums[half] == target) {
                if (half == 0) return 0;
                else if (nums[half - 1] < target) return half;
            }
            if (nums[half] < target) {
                L = half + 1;
            }
            else {
                R = half - 1;
            }
        }
        return -1;
    }

    int findLast(vector<int> nums, int target)
    {
        if (nums[nums.size() - 1] == target) return nums.size() - 1;
        auto L = 0;
        int R = nums.size() - 1;
        while (L <= R) {
            auto half = (R + L) / 2;
            if (nums[half] == target) {
                if (half == nums.size() - 1) return nums.size() - 1;
                else if (nums[half + 1] > target) return half;
            }
            if (nums[half] <= target) {
                L = half + 1;
            }
            else {
                R = half - 1;
            }
        }
        return -1;
    }
};