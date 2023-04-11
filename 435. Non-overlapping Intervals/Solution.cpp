class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto sortSecond =  [](vector<int> &first, vector<int> &second){
            return first[1] < second[1];
        };
        sort(intervals.begin(), intervals.end(), sortSecond);
        int high = intervals[0][1];
        int res = 0;
        for (int i = 1; i < intervals.size(); i++){
            if (high > intervals[i][0]) res++;
            else high = intervals[i][1];
        }
        return res;
    }
};
