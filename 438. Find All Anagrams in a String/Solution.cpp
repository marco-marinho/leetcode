class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> target;
        int n = p.size();
        for (auto c: p){
            if (!target[c]) target[c] = 1;
            else target[c]++;
        }
        vector<int> output;
        if (p.size() > s.size()) return output;
        for (auto c: s.substr(0, n-1)){
            if (target.count(c)) target[c]--;
        }
        char last = '\0';
        for (int i = 0; i <= s.size() - n; i++){
            if (target.count(last)) target[last]++;
            auto next = s[i + n - 1];
            if (target.count(next)) target[next]--;
            bool anagram = true;
            for (auto entry: target){
                if (entry.second) {
                    anagram = false;
                    break;
                }
            }
            if (anagram) output.push_back(i);
            last = s[i];
        }
        return output;
    }
};