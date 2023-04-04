class Solution {
public:

    static inline double calcM(int i, int j, vector<vector<int>>& coordinates){
        if (coordinates[i][0] - coordinates[j][0] == 0) return INFINITY;
        return double(coordinates[i][1] - coordinates[j][1]) / double(coordinates[i][0] - coordinates[j][0]);
    }

    bool checkStraightLine(vector<vector<int>> coordinates) {
        double m = calcM(0, 1, coordinates);
        for (int i = 1; i < coordinates.size() - 1; i++){
            if (calcM(i, i+1, coordinates) != m) return false;
        }
        return true;
    }
};
