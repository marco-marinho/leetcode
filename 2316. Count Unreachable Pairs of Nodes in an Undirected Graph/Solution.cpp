class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adjacency(n, vector<int>());

        for (auto entry: edges){
            adjacency[entry[0]].emplace_back(entry[1]);
            adjacency[entry[1]].emplace_back(entry[0]);
        }

        long long output = 0;
        long long visitedCount = 0;

        for (int i = 0; i < n; i++){
            if (visited[i]) continue;
            long long size = 0;
            stack<int> toVisit({i});
            while(!toVisit.empty()){
                auto curr = toVisit.top();
                toVisit.pop();
                if(visited[curr]) continue;
                visited[curr] = true;
                size++;
                for (auto n : adjacency[curr]){
                    if (visited[n]) continue;
                    toVisit.push(n);
                }
            }
            visitedCount += size;
            output += size * (n - visitedCount);
        }
        return output;
    }
};
