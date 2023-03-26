class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stq(stones.begin(), stones.end());
        while(stq.size() > 1){
            int first = stq.top();
            stq.pop();
            int second = stq.top();
            stq.pop();
            if (first != second){
                stq.push(first - second);
            }
        }
        if (stq.size() == 0) return 0;
        return stq.top();
    }   
};
