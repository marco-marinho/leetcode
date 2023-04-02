class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> memory(word1.size(), vector<int>(word2.size(), -1));
        return dp(0, 0, word1, word2, memory);
    }

    int dp(int idx1, int idx2, string &word1, string &word2, vector<vector<int>> &memory)
    {
        if (idx1 == word1.size()) return word2.size() - idx2;
        if (idx2 == word2.size()) return word1.size() - idx1;
        if (memory[idx1][idx2] != -1) return memory[idx1][idx2];

        if (word1[idx1] == word2[idx2]) {
            return memory[idx1][idx2] = dp(idx1 + 1, idx2 + 1, word1, word2, memory);
        }
        else {
            int inst = dp(idx1, idx2 + 1, word1, word2, memory);
            int del = dp(idx1 + 1, idx2, word1, word2, memory);
            int rep = dp(idx1 + 1, idx2 + 1, word1, word2, memory);
            return memory[idx1][idx2] = min(inst, min(del, rep)) + 1;
        }
    }
};
