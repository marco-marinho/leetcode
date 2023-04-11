class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRows = matrix.size();
        int nCols = matrix[0].size();
        if (matrix[0][0] > target || matrix[nRows - 1][nCols - 1] < target) return false;
        int col = nCols - 1;
        int row = 0;
        while(row < nRows && col >= 0){
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};
