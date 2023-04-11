class Solution {
public:
    string removeStars(string s) {
        stack<char> letters;
        for (auto c : s){
            if (c == '*') letters.pop();
            else letters.push(c);
        }
        string output(letters.size(), ' ');
        for (int i = letters.size() - 1; i >= 0; i--){
            output[i] = letters.top();
            letters.pop();
        }
        return output;
    }
};
