class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto num_strs = strs.size();
        if (num_strs == 1) return strs.at(0);
        string output;
        for (auto index = 0; index <= 200; index++) {
            if (index >= strs.at(0).size()) return output;
            auto current = strs.at(0)[index];
            for (auto sub_str = 1; sub_str < num_strs; sub_str++) {
                if (index >= strs.at(sub_str).size() || strs.at(sub_str)[index] != current) return output;
            }
            output.push_back(current);
        }
        return output;
    }

};