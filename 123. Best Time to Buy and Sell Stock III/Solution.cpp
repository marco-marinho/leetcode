class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int s1 = -prices[0];
        int s2 = INT_MIN/2;
        int s3 = INT_MIN/2;
        int s4 = INT_MIN/2;

        for(int i = 1; i < prices.size(); i++){
            s1 = max(s1, -prices[i]);
            s2 = max(s2, s1 + prices[i]);
            s3 = max(s3, s2 - prices[i]);
            s4 = max(s4, s3 + prices[i]);
        }

        return max(0, s4);
    }
};
