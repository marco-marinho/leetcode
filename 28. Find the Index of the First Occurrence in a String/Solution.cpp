class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); i++){
            if (haystack[i] == needle[0]){
                bool equal = haystack.substr(i, needle.size()) == needle;
                if (equal) return i;
            }
        }
        return -1;
    }
};
