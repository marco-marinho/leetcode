class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        int low = intervals[0][0];
        int high = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++){
            if (low <= intervals[i][1] && high >= intervals[i][0]){
                high = max(high, intervals[i][1]);
            }
            else {
                output.push_back({low, high});
                low = intervals[i][0];
                high = intervals[i][1];
            }
        }
        output.push_back({low, high});
        return output;
    }
};
