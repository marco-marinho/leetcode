class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> words;
        set<char> used;
        int idxPattern = 0;
        stringstream ss(s);
        string buff;
        while(getline(ss, buff, ' ')){
            char ident = pattern[idxPattern];
            idxPattern++;
            if (!words.count(buff) && !used.count(ident)) {
                words[buff] = ident;
                used.insert(ident);
            }
            else if (!words.count(buff) && used.count(ident)) return false;
            else if (words[buff] != ident) return false;
        }
        return idxPattern == pattern.size();
    }
};
