class Solution {
public:
    int uniquePathsWithObstacles(const vector<vector<int>> &obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> current(rows + 1, vector<int>(cols + 1, 0));
        current[1][1] = 1;
        for (int i = 1; i < rows + 1; i++){
            for (int j = 1; j < cols + 1; j++) {
                if (obstacleGrid[i - 1][j - 1]) {
                    current[i][j] = 0;
                }
                else {
                    current[i][j] += current[i - 1][j] + current[i][j - 1];
                }
            }
        }
        return current.back().back();
    }
};