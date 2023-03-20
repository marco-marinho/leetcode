class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<char>> rows;
        unordered_map<int, set<char>> cols;
        unordered_map<int, set<char>> box;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                auto element = board[i][j];
                auto boxid = 10*(i/3)+(j/3);
                if (element == '.') continue;
                if (!rows.count(i)) rows[i] = {element};
                else if(rows[i].count(element)) return false;
                else rows[i].insert(element);
                if (!cols.count(j)) cols[j] = {element};
                else if(cols[j].count(element)) return false;
                else cols[j].insert(element);
                if (!box.count(boxid)) box[boxid] = {element};
                else if(box[boxid].count(element)) return false;
                else box[boxid].insert(element);
            }
        }
        return true;
    }
};