class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> solutions;
        int last = graph.size() - 1;
        if (graph.size() == 0) return solutions;
        stack<vector<int>> q;
        q.push({0});
        while(!q.empty()){
            auto curr = q.top();
            q.pop();
            for(auto next : graph[curr.back()]){
                auto buff = curr;
                buff.push_back(next);
                if (next == last) solutions.push_back(buff);
                else q.push(buff);
            }
        }
        return solutions;
    }
};