class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int n_3 = 0;
        int n_2 = 1;
        int n_1 = 1;

        for (int i = n - 3; i >= 0; i--){
            int n_2_buff = n_2;
            int n_1_buff = n_1;
            n_1 += n_2 + n_3;
            n_3 = n_2_buff;
            n_2 = n_1_buff;
        }

        return n_1;
    }
};
