import java.util.ArrayList;
class Solution {

    ArrayList<int[]> zeroCoordinates = new ArrayList<>();
    ArrayList<int[]> oneCoordinates = new ArrayList<>();
    public int[][] updateMatrix(int[][] mat) {
        getZeroCoordinates(mat);
        return distances(mat.length, mat[0].length);
    }
    private void getZeroCoordinates(int[][] mat) {
        int nrows = mat.length;
        int ncols = mat[0].length;
        for(int row = 0; row < nrows; row++){
            for(int col = 0; col < ncols; col++){
                if(mat[row][col] == 0){
                    zeroCoordinates.add(new int[]{row, col});
                }
                else{
                    oneCoordinates.add(new int[]{row, col});
                }
            }
        }
    }

    private int[][] distances(int nrows, int ncols){
        int[][] output = new int[nrows][ncols];
        for(int[] oneCoordinate : oneCoordinates){
            output[oneCoordinate[0]][oneCoordinate[1]] = getDistance(oneCoordinate[0], oneCoordinate[1]);
        }
        return output;
    }

    private int getDistance(int row, int col){
        int distance = Integer.MAX_VALUE;
        for (int[] zeroCoordinate : zeroCoordinates) {
            int buff = Math.abs(zeroCoordinate[0] - row) + Math.abs(zeroCoordinate[1] - col);
            if(buff < distance){
                distance = buff;
                if(distance == 1){
                    break;
                }
            }
        }
        return distance;
    }

}