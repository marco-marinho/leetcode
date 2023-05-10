class Solution {
public:
    int maxProfit(const vector<int>& prices, int fee) {
        vector<vector<int>> res(prices.size(), vector<int>(2, 0));
        res[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++){
            res[i][0] = max(res[i - 1][0], res[i - 1][1] + prices[i] - fee);
            res[i][1] = max(res[i - 1][1], res[i - 1][0] - prices[i]);
        }
        return res[prices.size() - 1][0];
    }
};
