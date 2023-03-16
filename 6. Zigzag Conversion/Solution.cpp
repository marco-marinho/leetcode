class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string output;
        auto jump = numRows + numRows - 2;
        if (jump < 2) jump = 2;
        for (auto row = 0; row < numRows; row++){
            auto first_step = jump - (row * 2);
            auto second_step = row * 2;
            if (first_step <= 0) first_step = second_step;
            if (second_step <= 0) second_step = first_step;
            auto index = row;
            while (index < s.length()){
                output.push_back(s[index]);
                index += first_step;
                if (index < s.length()) output.push_back(s[index]);
                index += second_step;
            }
        }
        return output;
    }
};