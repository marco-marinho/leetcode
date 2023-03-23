class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        set<int> visited;
        int networks = 0;
        vector<vector<int>> adjacency{(size_t)n, vector<int>()};
        for (auto entry: connections){
            adjacency[entry[0]].emplace_back(entry[1]);
            adjacency[entry[1]].emplace_back(entry[0]);
        }
        for (int i = 0; i < n; i++){
            if (visited.find(i) != visited.end()) continue;
            networks++;
            stack<int> to_visit;
            to_visit.push(i);
            while(!to_visit.empty()){
                int curr = to_visit.top();
                to_visit.pop();
                if (visited.count(curr)) continue;
                visited.insert(curr);
                for (auto node : adjacency[curr]){
                    if (visited.find(node) != visited.end()) continue;
                    else to_visit.push(node);
                }
            }
        }
        return networks - 1;
    }
};
