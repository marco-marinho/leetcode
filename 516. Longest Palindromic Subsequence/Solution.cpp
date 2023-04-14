class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memory(s.size(), vector<int>(s.size(), -1));
        return getLongest(0, s.size() - 1, s, memory);
    }

    int getLongest(const int first, const int second, const string &s , vector<vector<int>> &memory){
        if (first == second) return 1;
        if (first > second) return 0;
        if (memory[first][second] != -1) return memory[first][second];
        if (s[first] == s[second]){
            return memory[first][second] = getLongest(first + 1, second - 1, s, memory) + 2;
        }
        else{
            return memory[first][second] = max(getLongest(first + 1, second, s, memory),
                                                getLongest(first, second - 1, s, memory));
        }
    }

};
