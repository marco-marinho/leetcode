class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for (int j = 0; j < cols; j++){
            dfs(0, j, grid);
            dfs(rows - 1, j, grid);
        }
        for (int i = 0; i < rows; i++){
            dfs(i, 0, grid);
            dfs(i, cols - 1, grid);
        }
        int count = 0;
        for(auto l: grid){
            for(auto v: l){
                if (v == 1) count++;
            }
        }
        return count;
    }

    void dfs(int row, int col, vector<vector<int>>& grid){
        if (row < 0 || row >= grid.size()
            || col < 0 || col >= grid[0].size()
            || grid[row][col] == 0) return;
        grid[row][col] = 0;
        dfs(row + 1, col, grid);
        dfs(row - 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);
    }


};
