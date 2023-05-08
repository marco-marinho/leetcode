class Solution {
public:
    static bool isVowel(const char &c){
        return c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int res = 0;
        for (int i = 0; i < k; i++){
            if (isVowel(s[i])) res++;
        }
        int output = res;
        for(int i = 1; i + k - 1 < s.size(); i++){
            if(isVowel(s[i - 1])) res--;
            if(isVowel(s[i + k - 1])) res++;
            output = max(output, res);
        }
        return output;
    }
};
