class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, vector<int>> groups;
        for(auto &num: arr){
            int nBits = countBits(num);
            if (!groups.count(nBits)){
                groups[nBits] = {num};
            }
            else groups[nBits].emplace_back(num);
        }
        vector<int> groupsVec;
        for (auto &[group, numVec] : groups){
            groupsVec.emplace_back(group);
            sort(numVec.begin(), numVec.end());
        }
        sort(groupsVec.begin(), groupsVec.end());
        vector<int> output;
        for (auto &group: groupsVec){
            output.insert(output.end(), groups[group].begin(), groups[group].end());
        }
        return output;
    }
    int countBits(int num){
        int count = 0;
        while(num > 0){
            if (num % 2 == 1) count++;
            num >>= 1;
        }
        return count;
    }
};
