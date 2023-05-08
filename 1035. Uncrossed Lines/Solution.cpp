class Solution {
public:
    int maxUncrossedLines(const vector<int>& nums1, const vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> memory(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(nums1[i - 1] == nums2[j - 1]){
                    memory[i][j] = 1 + memory[i - 1][j - 1];
                }
                else{
                    memory[i][j] = max(memory[i][j - 1], memory[i - 1][j]);
                }
            }
        }
        return memory[m][n];
    }
};
