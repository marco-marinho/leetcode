class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(const vector<int>& obstacles) {
        vector<int> res(obstacles.size(), 1);
        vector<int> lowest;

        for(int i = 0; i < obstacles.size(); i++){
            auto it = upper_bound(lowest.begin(), lowest.end(), obstacles[i]);
            res[i] = it - lowest.begin() + 1;
            if(it == lowest.end()) lowest.emplace_back(obstacles[i]);
            else *it = obstacles[i];
        }
        return res;
    }
};
