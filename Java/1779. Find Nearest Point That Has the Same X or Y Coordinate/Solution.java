public class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int idx = -1;
        int min = Integer.MAX_VALUE;
        for (int point = 0; point < points.length; point ++){
            if (points[point][0] == x || points[point][1] == y){
                int distance = Math.abs(points[point][0] - x) + Math.abs(points[point][1] - y);
                if (distance < min){
                    min = distance;
                    idx = point;
                }
            }
        }
        return idx;
    }
}
