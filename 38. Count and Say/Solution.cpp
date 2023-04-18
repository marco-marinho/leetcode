class Solution {
public:
    vector<pair<char, int>> intToCount(string n){
        vector<pair<char, int>> pieces;
        char cur = n[0];
        int count = 1;
        for (int i = 1; i < n.size(); i++){
            if (n[i] == cur) count++;
            else {
                pieces.emplace_back(cur, count);
                cur = n[i];
                count = 1;
            }
        }
        pieces.emplace_back(cur, count);
        return pieces;
    }

    string countToInt(const vector<pair<char, int>>& counts){
        string out;
        for (auto [val, count] : counts){
            out.append(to_string(count));
            out += val;
        }
        return out;
    }

    string countAndSay(const int itter){
        string n = "1";
        for (int i = 1; i < itter; i++){
            auto pieces = intToCount(n);
            n = countToInt(pieces);
        }
        return n;
    }

};
