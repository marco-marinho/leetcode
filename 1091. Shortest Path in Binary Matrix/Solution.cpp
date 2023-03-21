struct path {
    tuple<int, int> coords;
    int dist;
};

class ComparePath {
public:
    bool operator()(path first, path second)
    {
        if (first.dist >= second.dist) return true;
        return false;
    }
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0]) return -1;
        priority_queue<path, vector<path>, ComparePath> to_visit;
        set<tuple<int, int>> visited;
        int n = grid.size() - 1;
        tuple<int, int> target{n, n};
        to_visit.push({{0, 0}, 1});
        while (!to_visit.empty()) {
            path curr = to_visit.top();
            to_visit.pop();
            if (visited.count(curr.coords)) continue;
            if (curr.coords == target) return curr.dist;
            visited.insert(curr.coords);
            auto next = getNeighbours(curr.coords, n);
            for (auto nxt: next) {
                if (visited.count(nxt)) continue;
                if (grid[get<0>(nxt)][get<1>(nxt)] != 0) continue;
                to_visit.push({nxt, curr.dist + 1});
            }
        }
        return -1;
    }

    vector<tuple<int, int>> getNeighbours(tuple<int, int> coords, int n)
    {
        int x = get<0>(coords);
        int y = get<1>(coords);
        vector<tuple<int, int>> output;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if ((i == 0 && j == 0) || x + i < 0 || y + j < 0 || x + i > n || y + j > n) continue;
                output.emplace_back(x + i, y + j);
            }
        }
        return output;
    }
};