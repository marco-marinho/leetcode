class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> memory(satisfaction.size() + 1, vector<int>(satisfaction.size() + 1, -1));
        return calcSatisfaction(0, 1, satisfaction, memory);
    }
    int calcSatisfaction(int index, int time, vector<int>& satisfaction, vector<vector<int>> &memory){
        if (index >= satisfaction.size()) return 0;
        if (memory[index][time] != -1) return memory[index][time];
        return memory[index][time] = max(satisfaction[index] * time + calcSatisfaction(index + 1, time + 1, satisfaction, memory),
            calcSatisfaction(index + 1, time, satisfaction, memory));
    }
};
