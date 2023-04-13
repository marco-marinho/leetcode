class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> pos;
        for(int i = s.size() - 1; i >= 0; i--){
            if(!pos.count(s[i])) pos[s[i]] = i;
        }
        int last = 0;
        int start = 0;
        vector<int> output;
        for (int i = 0; i < s.size(); i++){
            if (i > last){
                output.emplace_back(last - start + 1);
                start = i;
            }
            if (pos[s[i]] > last) last = pos[s[i]];
        }
        output.emplace_back(last - start + 1);
        return output;
    }
};
