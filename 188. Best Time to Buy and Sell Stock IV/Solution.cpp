class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> states(2*k, INT_MIN / 2);
        states[0] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            states[0] = max(states[0], -prices[i]);
            states[1] = max(states[1], states[0] + prices[i]);
            for(int j = 2; j < 2*k; j+=2){
                states[j] = max(states[j], states[j - 1] - prices[i]);
                states[j + 1] = max(states[j + 1], states[j] + prices[i]);
            }
        }
        return max(0, states.back());
    }
};
