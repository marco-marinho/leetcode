class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int closed = 0;
        for (int i = 1; i < grid.size() - 1; i++){
            for (int j = 1; j < grid[0].size() - 1; j++){
                if (grid[i][j] == 0){
                    auto c = floodFill(i, j, grid);
                    if (c) closed++;
                }
            }
        }
        return closed;
    }

    bool floodFill(int row, int col, vector<vector<int>>& grid){
        vector<pair<int,int>> next{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int nRows = grid.size();
        int nCols = grid[0].size();
        stack<pair<int, int>> toVisit;
        toVisit.push({row, col});
        bool closed = true;
        while(!toVisit.empty()){
            auto [cRow, cCol] = toVisit.top();
            toVisit.pop();
            if (cRow == 0 || cRow == nRows - 1 || cCol == 0 || cCol == nCols -1){
                closed = false;
            }
            grid[cRow][cCol] = 2;
            for (auto [nRow, nCol] : next){
                auto fRow = cRow + nRow;
                auto fCol = cCol + nCol;
                if (fRow >= 0 && fRow < nRows && fCol >= 0 && fCol < nCols){
                    if (grid[fRow][fCol] == 0){
                        toVisit.push({fRow, fCol});
                    }
                }
            }
        }
        return closed;
    }

};
