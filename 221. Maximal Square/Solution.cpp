class Solution {
public:
    int maximalSquare(const vector<vector<char>>& matrix) noexcept {
        const size_t rows = matrix.size();
        const size_t cols = matrix[0].size();
        vector<vector<int>> sizes(rows + 1, vector<int>(cols + 1, 0));
        int max_len = 0;

        for (int i = 1; i <= rows; i++){
            for (int j = 1; j <= cols; j++){
                if (matrix[i - 1][j - 1] != '1') continue;
                sizes[i][j] = min({sizes[i - 1][j], sizes[i][j - 1], sizes[i - 1][j - 1]}) + 1;
                max_len = max(max_len, sizes[i][j]);
            }
        }

        return max_len * max_len;
    }
};
