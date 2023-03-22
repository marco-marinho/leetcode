class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_map<int, int>> connections;
        for (auto entry : roads){
            connections[entry[0]][entry[1]] = entry[2];
            connections[entry[1]][entry[0]] = entry[2];
        }
        auto connected = checkConnected(1, connections);
        int min = INT32_MAX;
        for (auto entry: roads){
            if (connected.count(entry[0]) && entry[2] < min) min = entry[2];
        }
        return min;
    }

    static set<int> checkConnected(int start, unordered_map<int, unordered_map<int, int>>& connections){
        set<int> visited;
        stack<int> toVisit;
        toVisit.push(start);
        while(!toVisit.empty()){
            auto curr = toVisit.top();
            toVisit.pop();
            if (visited.count(curr)) continue;
            visited.insert(curr);
            for (auto& entry: connections[curr]){
                toVisit.push(entry.first);
            }
        }
        return visited;
    }
};
