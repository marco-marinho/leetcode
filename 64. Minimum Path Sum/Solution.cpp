struct path_t{
    pair<int, int> coords;
    int dist;
};

class Path{
public:
    bool operator() (path_t first, path_t second){
        return first.dist > second.dist;
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        pair<int, int> target{grid.size() - 1, grid[0].size() - 1};
        pair<int, int> changes[4]{{1,0}, {0, 1}};
        priority_queue<path_t, vector<path_t>, Path> toVisit;
        set<pair<int, int>> visited;
        toVisit.push({{0, 0}, grid[0][0]});
        while(!toVisit.empty()){
            path_t current = toVisit.top();
            toVisit.pop();
            if (visited.find(current.coords) != visited.end()) continue;
            if (current.coords == target) return current.dist;
            visited.insert(current.coords);
            auto [x, y] = current.coords;
            for (auto [i, j] : changes){
                int nx = x+i; int ny = y+j;
                if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
                toVisit.push({{nx, ny}, current.dist + grid[nx][ny]});
            }
        }
        return -1;
    }
};
