class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        for (int i = 0; i < arr.size(); i++){
            int sum = 0;
            for(int j = 0; j + i < arr.size(); j++){
                sum += arr[i + j];
                if ((j + 1) % 2 != 0) res += sum;
            }
        }
        return res;
    }
};
