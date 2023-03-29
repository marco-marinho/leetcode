class Solution {
public:
    int numDecodings(string s) {
        vector<int> memory(s.size(), -1);
        return decode(s, 0, memory);
    }

    int decode(string&s, int index, vector<int> &memory){
        if (index == s.size()) return 1;
        if (s[index] == '0') return 0;
        if (index == s.size() - 1) return 1;
        if (memory[index] != -1) return memory[index];
        int ways = decode(s, index + 1, memory);
        int num = 10 * (s[index] - '0') + (s[index + 1] - '0');
        if (num >= 1 && num <= 26) ways += decode(s, index + 2, memory);
        return memory[index] = ways;
    }
};
