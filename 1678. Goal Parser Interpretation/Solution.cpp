class Solution {
public:
    string interpret(string command) {
        int p = 0;
        string output;
        while(p < command.size()){
            if (command[p] == 'G') {
                output += 'G';
                p++;
            }
            else if (command[p + 1] == ')'){
                output += 'o';
                p += 2;
            }
            else {
                output += "al";
                p += 4;
            }
        }
        return output;
    }
};
