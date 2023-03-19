class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        for (int i = 0; i < numRows; i++){
            output.push_back(genRow(i));
        }
        return output;
    }
    vector<int> genRow (int row) {
        vector<int> output(row + 1, 1);
        int n_1 = 1;
        for (int i = 1; i <= row; i++){
            n_1 = (n_1 * (row - i + 1)) / i;
            output[i] = n_1;
        }
        return output;
    }
};
