class Solution {
public:
    char findTheDifference(string s, string t) {
        int letters[26] = {0};
        for (int i = 0; i < s.size(); i++){
            letters[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++){
            if (letters[t[i] - 'a'] == 0) return t[i];
            letters[t[i] - 'a']--;
        }
        return ' ';
    }
};
