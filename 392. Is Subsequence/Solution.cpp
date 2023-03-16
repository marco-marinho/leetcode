class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        char target_idx = 0;
        for (char i : t){
            if (i == s[target_idx]) {
                target_idx++;
                if (target_idx >= s.size()) return true;
            }
        }
        return false;
    }
};
