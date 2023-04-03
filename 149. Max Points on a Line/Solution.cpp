class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 1;
        int output = 2;
        for(int i = 0; i < points.size(); i ++){
            unordered_map<double, int> ms;
            for (int j = 0; j < points.size(); j ++){
                if (i == j) continue;
                double m = double(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                ms[m]++;
            }
            for (const auto& entry : ms){
               output = max(output, entry.second + 1);
            }
        }
        return output;
    }
};
