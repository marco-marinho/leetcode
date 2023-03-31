typedef vector<vector<int>> imatrix;
typedef vector<vector<vector<long long>>> mem;
typedef long long LONG;

class Solution {
public:

    imatrix apples;
    int rows;
    int cols;

    int ways(vector<string>& pizza, int k) {
        rows = pizza.size();
        cols = pizza[0].size();
        apples = imatrix(rows, vector<int>(cols, 0));
        for (int r = rows - 1; r >= 0; --r){
            for (int c = cols - 1; c >= 0; c--){
                int i = pizza[r][c] == 'A';
                if (r + 1 < rows) i += apples[r + 1][c];
                if (c + 1 < cols) i += apples[r][c + 1];
                if (r + 1 < rows && c + 1 < cols) i -= apples[r + 1][c + 1];
                apples[r][c] = i;
            }
        }
        mem memory = mem(k, vector<vector<LONG>>(rows, vector<LONG>(cols, -1)));
        return dp(0, 0, 0, k, memory) % 1000000007;
    }

    LONG dp(int cut, int row, int col, int k, mem &memory){
        if (cut == k - 1) {
            return 1;
        }
        if (memory[cut][row][col] != -1) return memory[cut][row][col];
        LONG res = 0;
        for (int r = row + 1; r < rows; r++){
                if (apples[row][col] - apples[r][col] > 0 && apples[r][col] != 0){
                res += dp(cut + 1, r, col, k, memory);
            }
        }
        for (int c = col + 1; c < cols; c++){
            if (apples[row][col] - apples[row][c] > 0 && apples[row][c] != 0){
                res += dp(cut + 1, row, c, k, memory);
            }
        }
        return memory[cut][row][col] = res;
    }
};
