class Solution {
public:
    string longestPalindrome(string s) {
 if (s.length() < 2) return s;
        auto cur_max = 0;
        auto start = 0;
        auto end = 0;
        for (auto center = 0; center < s.length() - 1; center++){
            auto cur_size = 1;
            auto res = exploreString(s, center - 1, center + 1);
            if (s[center] == s[center + 1]){
                auto resBuff = exploreString(s, center - 1, center + 2);
                if (resBuff.size >= res.size) {
                    res = resBuff;
                    cur_size = 2;
                }
            }
            if (res.size + cur_size > cur_max) {
                cur_max = res.size + cur_size;
                start = res.start + 1;
                end = res.end - 1;
            }
        }
        return s.substr(start, end - start + 1);
    }
private:
     struct exploreRes{
        int size;
        int start;
        int end;
    };
     static exploreRes exploreString(string s, int cursor_start, int cursor_end){
         auto size = 0;
         while(cursor_start >= 0 && cursor_end <= s.length() - 1 && s[cursor_start] == s[cursor_end]){
             size += 2;
             cursor_start--;
             cursor_end++;
         }
         return exploreRes{.size = size, .start = cursor_start, .end = cursor_end};
    }
};