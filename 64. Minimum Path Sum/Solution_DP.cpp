class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int col = 0; col < grid[0].size(); col++){
            for (int row = 0; row < grid.size(); row++){
                if (col - 1 < 0 && row - 1 < 0) continue;
                else if (col - 1 < 0) grid[row][col] += grid[row - 1][col];
                else if (row - 1 < 0) grid[row][col] += grid[row][col - 1];
                else grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
