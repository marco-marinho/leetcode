class Solution {
public:
    struct result {
        set<tuple<int, int>> visited;
        bool flip;
    };

    void solve(vector<vector<char>> &board) {
        set<tuple<int, int>> visited;
        for (int x = 0; x < board.size(); x++){
            for (int y = 0; y < board[0].size(); y++){
                if (!visited.count({x, y}) && board[x][y] != 'X'){
                    auto res = checkFlip(board, x, y);
                    visited.insert(res.visited.begin(), res.visited.end());
                    if (res.flip){
                        for (auto coord: res.visited){
                            board[get<0>(coord)][get<1>(coord)] = 'X';
                        }
                    }
                }
            }
        }
    }

    result checkFlip(const vector<vector<char>> &board, int x, int y) {
        set<tuple<int, int>> visited;
        queue<tuple<int, int>> to_visit;
        to_visit.emplace(x, y);
        bool flippable = true;
        while (!to_visit.empty()) {
            auto curr = to_visit.front();
            to_visit.pop();
            if (visited.count(curr)) continue;
            visited.insert(curr);
            int curr_x = get<0>(curr);
            int curr_y = get<1>(curr);
            flippable &= isFlippable(curr_x, curr_y, board);
            if (curr_x - 1 >= 0 && board[curr_x - 1][curr_y] != 'X') to_visit.emplace(curr_x - 1, curr_y);
            if (curr_x + 1 < board.size() && board[curr_x + 1][curr_y] != 'X') to_visit.emplace(curr_x + 1, curr_y);
            if (curr_y - 1 >= 0 && board[curr_x][curr_y - 1] != 'X') to_visit.emplace(curr_x, curr_y - 1);
            if (curr_y + 1 < board[0].size() && board[curr_x][curr_y + 1] != 'X') to_visit.emplace(curr_x, curr_y + 1);
        }
        return {.visited = visited, .flip = flippable};
    }

    bool isFlippable(int x, int y, const vector<vector<char>> &board) {
        return !(x - 1 < 0 || y - 1 < 0
                 || x + 1 >= board.size()
                 || y + 1 >= board[0].size());
    }

};
