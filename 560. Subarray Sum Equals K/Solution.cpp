class Solution {
public:
    int subarraySum(const vector<int>& nums, const int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> freqs{{0, 1}};
        for (const auto &n : nums){
            sum += n;
            if (freqs[sum - k]) res += freqs[sum - k];
            freqs[sum]++;
        }
        return res;
    }
};
