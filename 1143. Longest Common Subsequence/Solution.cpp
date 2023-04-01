class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memory(text1.size(), vector<int>(text2.size(), -1));
        return lenDP(0, 0, text1, text2, memory);
    }

    int lenDP(int idxf, int idxs, string &text1, string &text2, vector<vector<int>> &memory){
        if (idxf >= text1.size() || idxs >= text2.size()) return 0;
        if (memory[idxf][idxs] != -1) return memory[idxf][idxs];

        if (text1[idxf] == text2[idxs]) {
            int res = 1 + lenDP(idxf+1, idxs+1, text1, text2, memory);
            return memory[idxf][idxs] = res;
        }
        else {
            int res = max(lenDP(idxf + 1, idxs, text1, text2, memory),
                        lenDP(idxf, idxs + 1, text1, text2, memory));
                        return memory[idxf][idxs] = res;
        }
    }

};
