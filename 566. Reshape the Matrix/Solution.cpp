class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int nRows = mat.size();
        if (nRows == 0) return mat;
        int nCols = mat[0].size();
        if (nRows * nCols != r * c) return mat;
        vector<vector<int>> output(r, vector<int>(c, 0));
        for (int i = 0; i < r * c; i++){
            output[i/c][i%c] = mat[i/nCols][i%nCols];
        }
        return output;
    }
};
