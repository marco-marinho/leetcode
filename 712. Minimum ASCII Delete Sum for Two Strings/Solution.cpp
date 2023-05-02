class Solution {
public:
    int minimumDeleteSum(const string &s1, const string &s2) {
        vector<vector<int>> memory(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return find(0, 0, s1, s2, memory);
    }

    int find(const int i, const int j, const string &s1, const string &s2, vector<vector<int>> &memory){
        if (i >= s1.size() && j >= s2.size()){
            return 0;
        }
        if (memory[i][j] != -1) return memory[i][j];
        if (i >= s1.size()){
            return memory[i][j] = static_cast<int>(s2[j]) + find(i, j + 1, s1, s2, memory);
        }
        if (j >= s2.size()){
            return memory[i][j] = static_cast<int>(s1[i]) + find(i + 1, j, s1, s2, memory);
        }
        if (s1[i] == s2[j]){
            return memory[i][j] = find(i + 1, j + 1, s1, s2, memory);
        }
        int del1 = static_cast<int>(s1[i]) + find(i + 1, j, s1, s2, memory);
        int del2 = static_cast<int>(s2[j]) + find(i, j + 1, s1, s2, memory);
        return memory[i][j] = min(del1, del2);
    }

};
