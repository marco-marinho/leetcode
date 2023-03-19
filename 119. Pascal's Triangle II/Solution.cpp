class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> output(rowIndex + 1, 1);
        long n_1 = 1;
        for (int i = 1; i <= rowIndex; i++){
            n_1 = (n_1 * (rowIndex + 1 - i)) / i;
            output[i] = n_1;
        }
        return output;
    }
};
