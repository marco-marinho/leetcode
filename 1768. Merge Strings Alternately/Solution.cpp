class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p = 0;
        string output;
        while (p < word1.size() && p < word2.size()){
            output += word1[p];
            output += word2[p];
            p++;
        }
        output += word1.substr(p);
        output += word2.substr(p);
        return output;
    }
};
