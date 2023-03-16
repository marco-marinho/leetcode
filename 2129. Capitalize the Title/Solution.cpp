class Solution {
public:
    string capitalizeTitle(string title) {
        int first = 0;
        while (first < title.size()) {
            int second = first + 1;
            while (second < title.size() && title[second] != ' ') {
                second++;
            }
            int start = first;
            if (second - first >= 3) {
                title[first] = (char)toupper(title[first]);
                start++;
            }
            for (int i = start; i < second; i++) {
                title[i] = (char)tolower(title[i]);
            }
            first = second + 1;
        }
        return title;
    }
};
