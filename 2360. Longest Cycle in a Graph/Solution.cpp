class Solution {
public:
    int longestCycle(vector<int>& edges) {
        set<int> checked;
        int max_cycle = -1;
        for (int i = 0; i < edges.size(); i++){
            if(checked.find(i) != checked.end()) continue;
            stack<int> to_visit({i});
            map<int, int> visited;
            int steps = 0;
            while(!to_visit.empty()){
                auto curr = to_visit.top();
                if(checked.find(curr) != checked.end()) break;
                to_visit.pop();
                if (visited.find(curr) != visited.end()){
                    max_cycle = max(max_cycle, steps - visited[curr]);
                    break;
                }
                if(edges[curr] == -1) break;
                to_visit.push(edges[curr]);
                visited[curr] = steps;
                steps++;
            }
            for (auto [node, steps] : visited){
                checked.insert(node);
            }
        }
        return max_cycle;
    }
};
