class Solution {
public:
    int minFallingPathSum(const vector<vector<int>>& matrix) {
        int output = INT_MAX;
        vector<vector<int>> memory(matrix.size(), vector<int>(matrix.size(), INT_MIN));
        for (int i = 0; i < matrix.size(); i++){
            output = min(output, find(0, i, matrix, memory));
        }
        return output;
    }

    int find(int i, int j, const vector<vector<int>>& matrix, vector<vector<int>> &memory){
        if (i == matrix.size()){
            return 0;
        }
        if ( j < 0 || j == matrix.size()){
            return INT_MAX;
        }
        if (memory[i][j] != INT_MIN) return memory[i][j];

        int output = find(i + 1, j, matrix, memory);
        output = min(output, find(i + 1, j - 1, matrix, memory));
        output = min(output, find(i + 1, j + 1, matrix, memory));

        return memory[i][j] = output + matrix[i][j];
    }

};
