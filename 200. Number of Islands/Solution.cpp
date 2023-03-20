class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    islands++;
                    floodFill(i, j, grid);
                }
            }
        }
        return islands;
    }
    void floodFill(int row, int col, vector<vector<char>> &grid) {
        if (grid[row][col] == '1') grid[row][col] = 'X';
        else return;
        for (int i = -1; i<2; i+=2){
            auto nrow = row+i;
            auto ncol = col+i;
            if (nrow >= 0 && nrow < grid.size()) floodFill(nrow, col, grid);
            if (ncol >= 0 && ncol < grid[0].size()) floodFill(row, ncol, grid);
        }
    }
};