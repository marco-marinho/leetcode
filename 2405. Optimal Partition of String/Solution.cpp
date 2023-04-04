class Solution {
public:
    int partitionString(string s) {
        set<char> letters;
        int res = 1;
        for (auto c : s){
            if (letters.count(c)){
                res++;
                letters.clear();
            }
            letters.insert(c);
        }
        return res;
    }
};
