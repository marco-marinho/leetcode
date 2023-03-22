class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        int n_2 = 0;
        int n_1 = 1;
        for (int i = 0; i < n - 1; i++){
            int next = n_1 + n_2;
            n_2 = n_1;
            n_1 = next;
        }
        return n_1;
    }
};
