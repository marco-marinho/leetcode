class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        fliplr(matrix);
    }

    static inline void transpose(vector<vector<int>> &matrix){
        for (int row = 0; row < matrix.size(); row++){
            for (int col = row + 1; col < matrix.size(); col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }

    static inline void fliplr(vector<vector<int>> &matrix){
        for (int row = 0; row < matrix.size(); row++){
            for (int col = 0; col < matrix.size()/2; col++){
                swap(matrix[row][col], matrix[row][matrix.size() - 1 - col]);
            }
        }
    }

};
