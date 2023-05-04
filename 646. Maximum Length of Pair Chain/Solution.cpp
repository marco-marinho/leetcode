class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> res(pairs.size() + 1, 1);
        for (int j = 1; j < pairs.size(); j++){
            for (int i = 0; i < j; i++){
                if (pairs[j][0] > pairs[i][1]){
                    res[j] = max(res[j], res[i] + 1);
                }
            }
        }
        return *max_element(res.begin(), res.end());
    }
};
