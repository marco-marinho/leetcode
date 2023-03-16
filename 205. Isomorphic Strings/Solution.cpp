class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> direct, inverse;
        for (int i = 0; i < s.size(); i++) {
            if (direct[s[i]] && direct[s[i]] != t[i]) return false;
            if (inverse[t[i]] && inverse[t[i]] != s[i]) return false;
            direct[s[i]] = t[i];
            inverse[t[i]] = s[i];
        }
        return true;
    }
};
