public class Solution {
    public int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        int multiplier = 1;
        while(n >= multiplier){
            int digit = (n % (multiplier*10)) / (multiplier);
            prod *= digit;
            sum += digit;
            multiplier *= 10;
        }
        return prod - sum;
    }
}
