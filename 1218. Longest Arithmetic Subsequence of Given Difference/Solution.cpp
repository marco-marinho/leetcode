class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> lens;
        lens[arr[0]] = 1;
        for(int i = 1; i < arr.size(); i++){
            int key = arr[i] - difference;
            if (lens.count(key)){
                lens[arr[i]] = lens[arr[i] - difference] + 1;
            }
            else lens[arr[i]] = 1;
        }

        int maxx = 1;
        for(const auto &[key, val] : lens){
            maxx = max(maxx, val);
        }
        return maxx;
    }
};
