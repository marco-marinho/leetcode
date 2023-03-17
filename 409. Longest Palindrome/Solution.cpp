class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        for (char c : s){
            if (counts[c]) {
                counts[c] += 1;
            }
            else counts[c] = 1;
        }
        int len = 0;
        bool summed_1 = false;
        for (auto & count : counts){
            int rest = 0;
            if (count.second >= 2) {
                len += count.second - (count.second % 2);
                rest = (count.second % 2);
            }
            if (!summed_1 && (count.second == 1 || rest == 1)) {
                len++;
                summed_1 = true;
            }
        }
        return len;
    }
};
