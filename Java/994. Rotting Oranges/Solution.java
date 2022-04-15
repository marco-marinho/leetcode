import java.util.LinkedList;
class Solution {

    private final LinkedList<int[]> newRottenCoordinates = new LinkedList<>();
    private int num_rotten = 0;
    private int num_oranges = 0;
    private int nrows = 0;
    private int ncols = 0;
    private int time = 0;
    private final int[][] spread_coords = {{1, 0}, {-1, 0}, {0 ,1}, {0, -1}};

    public int orangesRotting(int[][] grid) {
        init_count(grid);
        int last_roten = num_rotten;
        while(true){
            if(num_rotten == num_oranges){
                break;
            }
            rot(grid);
            time++;
            if(last_roten == num_rotten){
                time = -1;
                break;
            }
            else{
                last_roten = num_rotten;
            }
        }
        return time;
    }

    private void rot(int[][] grid){
        int qrottenlen = newRottenCoordinates.size();
        for(int i = 0; i < qrottenlen; i++){
            int[] rot = newRottenCoordinates.removeFirst();
            for(int[] coord: spread_coords){
                int[] rot_spread = {rot[0] + coord[0], rot[1] + coord[1]};
                if(rot_spread[0] >= 0 && rot_spread[0] < nrows && rot_spread[1] >=0 && rot_spread[1] < ncols){
                    if(grid[rot_spread[0]][rot_spread[1]] == 1){
                        grid[rot_spread[0]][rot_spread[1]] = 2;
                        newRottenCoordinates.add(rot_spread);
                        num_rotten++;
                    }
                }
            }
        }
    }

    private void init_count(int[][] grid){
        nrows = grid.length;
        ncols = grid[0].length;
        for(int row = 0; row < nrows; row++){
            for(int col = 0; col < ncols; col++){
                if(grid[row][col] == 2){
                    newRottenCoordinates.add(new int[]{row, col});
                    num_rotten++;
                    num_oranges++;
                }
                else if(grid[row][col] == 1){
                    num_oranges++;
                }
            }
        }
    }
}