class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_value = INT_MAX;
        for (int i = 0; i < prices.size(); i++){
            if (prices[i] < min_value) min_value = prices[i];
            int profit = prices[i] - min_value;
            if (profit > max_profit) max_profit = profit;
        }
        return max_profit;
    }
};
