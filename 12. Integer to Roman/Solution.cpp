class Solution {
public:
    string intToRoman(int num) {
        string res;
        while(num > 0){
           for (int i = 0; i < 13; i++){
               auto table_entry = table[i];
               if (num / table_entry.num > 0){
                   res += table_entry.rom;
                   num -= table_entry.num;
                   break;
               }
           }
        }
        return res;
    }
private:
    struct conversion_t{
        const int num;
        const char* rom;
    };
    static constexpr conversion_t table[] = {{1000, "M"},
                                             {900, "CM"},
                                             {500, "D"},
                                             {400, "CD"},
                                             {100, "C"},
                                             {90, "XC"},
                                             {50, "L"},
                                             {40, "XL"},
                                             {10, "X"},
                                             {9, "IX"},
                                            {5, "V"},
                                             {4, "IV"},
                                             {1, "I"}};
};