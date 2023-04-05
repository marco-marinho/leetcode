class Solution {
public:
    string freqAlphabets(string s) {
        int p = s.size() - 1;
        string output;
        while(p >= 0){
            if (s[p] != '#'){
                output += 'a' + (s[p] - '1');
                p--;
            }
            else {
                output += 'a' + (10 * (s[p - 2] - '0') + (s[p - 1] - '0')) - 1;
                p -= 3;
            }
        }
        reverse(output.begin(), output.end());
        return output;
    }
};
