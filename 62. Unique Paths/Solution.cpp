class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> n_2(n, 1);
        vector<int> n_1(n, 1);
        for (int i = 0; i < m - 1; i++){
            for (int j = 1; j < n; j++){
                n_1[j] = n_1[j - 1] + n_2[j];
            }
            n_2 = n_1;
        }
        return n_1.back();
    }
};
