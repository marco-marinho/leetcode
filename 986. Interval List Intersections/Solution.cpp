class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        vector<vector<int>> output;

        int first_idx = 0;
        int second_idx = 0;

        while(first_idx < firstList.size() && second_idx < secondList.size()){
            int start = max(firstList[first_idx][0], secondList[second_idx][0]);
            int end = min(firstList[first_idx][1], secondList[second_idx][1]);
            if (start <= end) output.push_back({start, end});
            if (firstList[first_idx][1] < secondList[second_idx][1]) first_idx++;
            else second_idx++;
        }

        return output;
    }
};
