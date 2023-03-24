class Solution {
public:
    int characterReplacement(string s, int k) {
        int counts[26] = {0};
        int p0 = 0;
        int p1 = 0;
        int max = 0;
        counts[s[p0] - 'A'] = 1;
        while(p1 < s.size()){
            int maxCount = getLargest(counts);
            int size = p1 - p0 + 1;
            if (size - maxCount > k){
                counts[s[p0] - 'A']--;
                p0++;
            }
            else if (size > max) max = size;
            p1++;
            if (p1 < s.size()) counts[s[p1] - 'A']++;
        }
        return max;
    }
    int getLargest(int* count){
        int max = 0;
        for (int i = 0; i < 26; i++){
            if (count[i] > max) max = count[i];
        }
        return max;
    }
};
