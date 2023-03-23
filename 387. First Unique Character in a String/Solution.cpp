class Solution {
public:
    int firstUniqChar(string s) {
        set<char> skip;
        for (int i = 0; i < s.size(); i++){
            char current = s[i];
            if (skip.count(current)) continue;
            for (int j = i + 1; j < s.size(); j++){
                if (current == s[j]) {
                    skip.insert(current);
                    break;
                }
            }
            if (!skip.count(current)) return i;
        }
        return -1;
    }
};