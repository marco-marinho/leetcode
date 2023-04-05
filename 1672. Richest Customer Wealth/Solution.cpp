class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        int n = accounts[0].size();
        int res = 0;
        for (int i = 0; i < m; i++){
            int currSum = 0;
            for (int j = 0; j < n; j++){
                currSum += accounts[i][j];
            }
            res = max(res, currSum);
        }
        return res;
    }
};
