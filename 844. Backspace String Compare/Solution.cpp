class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> first = stringToStack(s);
        stack<char> second = stringToStack(t);
        while(!first.empty() && !second.empty()){
            if(first.top() != second.top()) return false;
            first.pop();
            second.pop();
        }
        if(!first.empty() || !second.empty()) return false;
        return true;
    }
private:
    stack<char> stringToStack(const string& s){
        stack<char> output;
        for(char ch : s){
            if(ch == '#'){
                if(!output.empty()) output.pop();
            }else{
                output.push(ch);
            }
        }
        return output;
    }
};
