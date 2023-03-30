class Solution {
public:
    unordered_map<string, bool> memory;

    bool isScramble(string s1, string s2) {
    if (s1.size() == 1) return s1 == s2;
    if (s1 == s2)return true;

    string key = (s1 + ":" + s2);
    if (memory.find(key) != memory.end()) {
        return memory[key];
    }

    int n = s1.size();
    bool res = false;
    for (int i = 1; i < n; ++i)
    {
        if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
        || (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))){
            res = true;
            break;
        }
    }
    return memory[key] = res;
    }
};
