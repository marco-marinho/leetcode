class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        queue<pair<int, int>> d7;
        queue<pair<int, int>> d30;
        int cost = 0;
        for (auto d: days){
            while(!d7.empty() && d7.front().first <= d - 7) d7.pop();
            while(!d30.empty() && d30.front().first <= d - 30) d30.pop();
            d7.push({d, cost + costs[1]});
            d30.push({d, cost + costs[2]});
            cost = cost + costs[0];
            if(!d7.empty()) cost = min(cost, d7.front().second);
            if(!d30.empty()) cost = min(cost, d30.front().second);
        }
        return cost;
    }
};
