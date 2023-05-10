class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memory(prices.size(), vector<int>(2, INT_MIN));
        return find(0, 0, prices, memory);
    }

    int find(int i, int s, vector<int>& prices, vector<vector<int>> &memory){
        if(i >= prices.size()) return 0;

        if(memory[i][s] != INT_MIN) return memory[i][s];

        if (s == 0){
            return memory[i][s] = max(find(i + 1, 0, prices, memory),
                                      find(i + 1, 1, prices, memory) - prices[i]);
        }
        else {
            return memory[i][s] = max(prices[i] + find(i + 2, 0, prices, memory),
                                      find(i + 1, 1, prices, memory));
        }

    }

};
