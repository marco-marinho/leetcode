class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memory(s.size(), -1);
        return breaker(0, s, wordDict, memory);
    }

    bool breaker(int idx, string &s, vector<string>& wordDict, vector<int> &memory){
        if (memory[idx] != -1) return memory[idx];
        bool broken = false;
        for (auto w : wordDict){
            if (s.size() - idx < w.size()) continue;
            if (s.substr(idx, w.size()) == w){
                if (idx + w.size() == s.size()) return true;
                broken = broken || breaker(idx + w.size(), s, wordDict, memory);
            }
        }
        return memory[idx] = broken;
    }
};
