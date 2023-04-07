class NumArray {
public:
    vector<int> cummSum;
    NumArray(vector<int>& nums) {
        cummSum = vector<int>(nums.size(), 0);
        int prev = 0;
        for (int i = 0; i < nums.size(); i++){
            prev += nums[i];
            cummSum[i] = prev;
        }
    }

    int sumRange(int left, int right) {
        int sum = cummSum[right];
        if (left > 0) sum -= cummSum[left - 1];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
