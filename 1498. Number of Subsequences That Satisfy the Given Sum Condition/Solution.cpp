constexpr int mod = 1000000007;

template<int N>
struct powTable {
    constexpr powTable() : vals() {
        vals[0] = 1;
        for (auto i = 1; i < N; ++i)
            vals[i] = (vals[i -1] * 2) % mod; 
    }
    int vals[N];
};

class Solution {
private:
    static constexpr auto pow2 = powTable<100000>();

public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int right = nums.size() - 1;
        int left = 0;
        
        while(left <= right){
            if(nums[left] + nums[right] <= target){
                res = (res + pow2.vals[right - left]) % mod;
                left++;
            }
            else{
                right--;  
            }
        }
        
        return res ;
    }
};
