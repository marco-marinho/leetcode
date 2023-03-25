class Solution {
public:
    string decodeString(string s) {
        stack<int> multipliers;
        stack<string> parts;
        int num = 0;
        string temp = "";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '[') {
                parts.push(temp);
                multipliers.push(num);
                num = 0;
                temp = "";
            }
            else if (s[i] == ']') {        
                int mult = multipliers.top();
                multipliers.pop();
                string next = "";
                for (int j = 0; j < mult; j++) next += temp;
                string prev = parts.top();
                parts.pop();
                temp = prev + next;
            }
            else if (isdigit(s[i])){
                num = 10*num + s[i] - '0';
            }
            else temp += s[i];
        }
        return temp;
    }
};
