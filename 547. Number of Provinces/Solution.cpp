class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        set<int> visited;
        for (int i = 0; i < isConnected.size(); i++){
            if (visited.count(i)) continue;
            queue<int> to_visit{{i}};
            visited.insert(i);
            provinces++;
            while(!to_visit.empty()){
                auto current = to_visit.front();
                to_visit.pop();
                for (int j = 0; j < isConnected[current].size(); j++){
                    if (i != j && isConnected[current][j] && !visited.count(j)) {
                        to_visit.push(j);
                        visited.insert(j);
                    }
                }
            }
        }
        return provinces;
    }
};