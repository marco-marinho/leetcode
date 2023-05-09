class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        int total = n*m;

        int col_start = 0;
        int col_end = m - 1;
        int row_start = 0;
        int row_end = n - 1;
        int count = 0;

        vector<int> output(total, 0);

        while(count < total){
            for(int i = col_start; count < total && i <= col_end; i++) {
                output[count++] = matrix[row_start][i];
            }
            row_start++;
            for(int j = row_start; count < total && j <= row_end; j++){
                output[count++] = matrix[j][col_end];
            }
            col_end--;
            for(int i = col_end; count < total && i >= col_start; i--){
                output[count++] = matrix[row_end][i];
            }
            row_end--;
            for(int j = row_end; count < total && j >= row_start; j--){
                output[count++] = matrix[j][col_start];
            }
            col_start++;
        }

        return output;
    }
};


