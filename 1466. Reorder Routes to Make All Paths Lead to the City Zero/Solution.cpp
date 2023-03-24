class Solution {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<vector<pair<int, bool>>> adjacency(n, vector<pair<int, bool>>());
        int changes = 0;
        for (auto c: connections) {
            adjacency[c[0]].emplace_back(c[1], true);
            adjacency[c[1]].emplace_back(c[0], false);
        }
        stack<int> to_visit({0});
        set<int> visited{};
        while (!to_visit.empty()) {
            auto curr = to_visit.top();
            to_visit.pop();
            visited.insert(curr);
            for (auto [next, edge]: adjacency[curr]) {
                if (visited.find(next) != visited.end()) continue;
                if (edge) changes++;
                to_visit.push(next);
            }
        }
        return changes;
    }
};
