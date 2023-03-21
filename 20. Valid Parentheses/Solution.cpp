class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        for (auto c : s){
            if (c == '(' || c == '[' || c == '{') open.push(c);
            else{
                if (open.empty()) return false;
                auto last = open.top();
                open.pop();
                if ((c == ')' && last != '(')
                || (c == ']' && last != '[')
                || (c == '}' && last != '{')) return false;
            }
        }
        if (!open.empty()) return false;
        return true;
    }
};
