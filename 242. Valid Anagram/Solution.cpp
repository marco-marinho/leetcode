class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int sCnt[26] = {0};
        int tCnt[26] = {0};
        for (int i = 0; i < s.size(); i++){
            sCnt[s[i] - 'a']++;
            tCnt[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++){
            if (sCnt[i] != tCnt[i]) return false;
        }
        return true;
    }
};
