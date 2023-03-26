class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> solutions;
        backTrack(n, 0, "", solutions);
        return solutions;
    }

    void backTrack(int n, int open, string current, vector<string> &solutions){
        if (current.size() == 2*n && open == 0){
            solutions.emplace_back(current);
            return;
        }
        if (current.size() >= 2*n) return;
        if (open < n){
            backTrack(n, open+1, current + "(", solutions);
        }
        if (open > 0){
            backTrack(n, open-1, current + ")" , solutions);
        }
    }

};
