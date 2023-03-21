class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int p1 = 0;
        int p2 = 0;
        long long res = 0;
        while(p2 < nums.size()){
            if (nums[p2]){
                long long diff = p2 - p1;
                if (diff) res += calcContrib(diff);
                p2++;
                p1 = p2;
            }
            else p2++;
        }
        res += calcContrib(p2 - p1);
        return res;
    }
    long long calcContrib(long long diff){
        return ((diff + 1) * diff) / 2;
    }
};