class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> current;
        int idxPush = 0;
        int idxPop = 0;
        while(idxPush < pushed.size()){
            if (!current.empty() && current.top() == popped[idxPop]){
                current.pop();
                idxPop++;
            }
            else{
                current.push(pushed[idxPush]);
                idxPush++;
            }
        }
        while(!current.empty() && idxPop < popped.size()){
            if (current.top() != popped[idxPop]) return false;
            current.pop();
            idxPop++;
        }
        return true;
    }
};
