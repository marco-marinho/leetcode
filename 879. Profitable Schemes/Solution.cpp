class Solution {
    typedef vector<vector<vector<int>>> tensor3;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        tensor3 memory = vector(101, vector<vector<int>>(101, vector<int>(101, -1)));
        return profitable(0, n, 0, minProfit, group, profit, memory);
    }

    int profitable(const int idx, const int disp,const  int total, const int minProfit, const vector<int>& group, const vector<int>& profit, tensor3 &memory){
        if (idx >= group.size()){
            if (total >= minProfit) return 1;
            return 0;
        }
        if (memory[idx][disp][total] != -1) return memory[idx][disp][total];
        long long count = profitable(idx + 1, disp, total, minProfit, group, profit, memory);
        if(disp - group[idx] >= 0){
            count += profitable(idx + 1, disp - group[idx], min(minProfit, total + profit[idx]), minProfit, group, profit, memory);
        }

        return memory[idx][disp][total] = (int)(count % (1000000000L + 7));
    }
};