class Solution {
public:
    int numDistinct(const string &s, const string &t) {
        vector<vector<int>> memory(s.size(), vector<int>(t.size(), -1));
        return find(0, 0, s, t, memory);
    }

    int find(int i, int j, const string &s, const string &t, vector<vector<int>> &memory){
        if (j == t.size()) return 1;
        else if (i == s.size()) return 0;

        if(memory[i][j] != -1) return memory[i][j];

        if(s[i] != t[j]){
            return memory[i][j] = find(i + 1, j, s, t, memory);
        }
        else{
            return memory[i][j] = find(i + 1, j + 1, s, t, memory) + find(i + 1, j, s, t, memory);
        }

    }

};
