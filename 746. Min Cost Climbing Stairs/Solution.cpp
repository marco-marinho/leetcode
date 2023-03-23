class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n_2 = cost[0];
        int n_1 = cost[1];
        for (int i = 2; i < cost.size(); i++){
            int next = min(n_1, n_2) + cost[i];
            n_2 = n_1;
            n_1 = next;
        }
        return min(n_2, n_1);
    }
};
