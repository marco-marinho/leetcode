typedef vector<vector<int>> imatrix;

class NumMatrix {
public:

    imatrix accm;
    int rows;
    int cols;

    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        accm = imatrix(rows, vector<int>(cols, 0));
        for (int c = cols - 1; c >= 0; --c){
            for(int r = rows - 1; r >= 0; r--){
                int buff = matrix[r][c];
                if (r + 1 < rows) buff += accm[r + 1][c];
                if (c + 1 < cols) buff += accm[r][c + 1];
                if (r + 1 < rows && c + 1 < cols) buff -= accm[r + 1][c + 1];
                accm[r][c] = buff;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = accm[row1][col1];
        if (row2 + 1 < rows) res -= accm[row2 + 1][col1];
        if (col2 + 1 < cols) res -= accm[row1][col2 + 1];
        if (row2 + 1 < rows && col2 + 1 < cols) res += accm[row2 + 1][col2 + 1];
        return res;
    }
};