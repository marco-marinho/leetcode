class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRows = matrix.size();
        int nCols = matrix[0].size();
        int num_els = nRows * nCols;
        int L = 0;
        int R = num_els - 1;

        while (L <= R) {
            int half = (L + R) / 2;
            int row = half / nCols;
            int col = half % nCols;

            int element = matrix[row][col];

            if (element == target) return true;
            if (target > element) L = half + 1;
            else R = half - 1;
        }
        return false;
    }
};