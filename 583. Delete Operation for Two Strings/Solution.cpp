class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memory(word1.size(), vector<int>(word2.size(), -1));

        return dp(0, 0, word1, word2, memory);
    }

    int dp(int idxf, int idxs, string &word1, string &word2, vector<vector<int>> &memory){
        if (idxf >= word1.size()) return word2.size() - idxs;
        if (idxs >= word2.size()) return word1.size() - idxf;

        if (memory[idxf][idxs] != -1) return memory[idxf][idxs];

        if (word1[idxf] == word2[idxs]) {
            return memory[idxf][idxs] = dp(idxf + 1, idxs + 1, word1, word2, memory);
        }
        else{
            return memory[idxf][idxs] = 1 + min(dp(idxf + 1, idxs, word1, word2, memory),
                                            dp(idxf, idxs + 1, word1, word2, memory));
        }

    }

};
