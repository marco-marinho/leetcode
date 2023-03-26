class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] != word[0]) continue;
                bool found = dfs({i, j}, 0, board, word);
                if (found) return true;
            }
        }
        return false;
    }
    bool dfs(pair<int, int> coords, int idx, vector<vector<char>>& board, string& word){
        if (board[coords.first][coords.second] != word[idx]) return false;
        if (idx >= word.size() - 1) return true;
        bool ret = false;
        vector<pair<int, int>> movement{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [i, j] : movement){
            pair<int, int> ncoords = {coords.first + i, coords.second + j};
            if (ncoords.first < 0 || ncoords.first >= board.size() || ncoords.second < 0 || ncoords.second >= board[0].size()) continue;
            board[coords.first][coords.second] = '#';
            ret = ret || dfs(ncoords, idx + 1, board, word);
            board[coords.first][coords.second] = word[idx];
        }
        return ret;
    }
};
