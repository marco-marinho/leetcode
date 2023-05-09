class Solution {
public:
    int minInsertions(const string &s) {
        int n = s.size();
        vector<vector<int>> res(n + 1, vector<int>(n + 1, 0));

        for(int i = 0; i <= n; i++){
            for (int j = 0; j <= n; j++){
                if (i == 0 || j == 0){
                    res[i][j] = 0;
                }
                else if (s[i - 1] == s[n - j]){
                    res[i][j] = res[i - 1][j - 1] + 1;
                }
                else {
                    res[i][j] = max(res[i - 1][j], res[i][j - 1]);
                }
            }
        }

        return n - res[n][n];
    }
};
