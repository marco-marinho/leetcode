class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letters;
        for (auto c : magazine){
            if (!letters[c]) letters[c] = 1;
            else letters[c] += 1;
        }
        for (auto c : ransomNote){
            if (!letters[c] || letters[c] < 1) return false;
            letters[c] -= 1;
        }
        return true;
    }
};
