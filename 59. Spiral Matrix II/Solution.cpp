class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int colOffset = 0;
        int rowOffset = 0;
        int curr = 1;
        int row = 0;
        int col = 0;
        int state = RIGHT;
        vector<vector<int>> output(n, vector<int>(n, 0));
        while(curr <= n * n){
            output[row][col] = curr;
            curr++;
            switch (state){
                case RIGHT:
                   col++;
                   if (col == n - colOffset){
                       col--;
                       row++;
                       state = DOWN;
                   }
                   break;
                case DOWN:
                    row++;
                    if (row == n - rowOffset){
                        row--;
                        col--;
                        state = LEFT;
                        rowOffset++;
                    }
                    break;
                case LEFT:
                    col--;
                    if (col == colOffset - 1){
                        col++;
                        row--;
                        state = UP;
                        colOffset++;
                    }
                    break;
                case UP:
                    row--;
                    if (row == rowOffset - 1){
                        row++;
                        col++;
                        state = RIGHT;
                    }
                    break;
            }
        }
        return output;
    }
private:

    enum status{
        RIGHT,
        DOWN,
        LEFT,
        UP,
    };

};
