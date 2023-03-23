class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> output{""};
        for (auto entry: digits){
            int num = entry - '2';
            int len = 3;
            if (num == 5 || num == 7) len = 4;
            int letter = num * 3;
            if (num == 6 || num == 7) letter++;
            vector<string> buff;
            for (int i = letter; i < letter + len; i++){
                for(auto curr : output){
                    auto lbuff = curr;
                    lbuff += (char) 'a' + i;
                    buff.push_back(lbuff);
                }
            }
            output = buff;
        }
        return output;
    }
};
