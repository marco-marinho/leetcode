class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<size_t, vector<string>> groups;
        for (const auto &s: strs){
            auto key = genKey(s);
            if (!groups.count(key)) groups[key] = {s};
            else groups[key].emplace_back(s);
        }
        vector<vector<string>> output;
        for (auto &[_, group] : groups){
            output.push_back(group);
        }
        return output;
    }

    size_t genKey(const string &s){
        int count[26] = {0};
        for (const auto &c : s){
            count[c - 'a']++;
        }
        std::hash<int> hasher;
        size_t answer = 0;
        for (const auto &i : count){
            answer ^= hasher(i) + 0x9e3779b9 +
                    (answer << 6) + (answer >> 2);
        }
        return answer;
    }
};