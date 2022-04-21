class Solution {
    public boolean isHappy(int n) {
        ArrayList<Integer> result = new ArrayList<>();
        int res = sumSquareDigits(n);
        result.add(res);
        while(res != 1){
            res = sumSquareDigits(res);
            if (result.contains(res)){
                break;
            }
            result.add(res);
        }
        return res == 1;
    }
    private int sumSquareDigits(int n) {
        int sum = 0;
        long multiplier = 1;
        while(n >= multiplier){
            int digit = (int) (n % (multiplier * 10) / multiplier);
            sum += digit*digit;
            multiplier *= 10;
        }
        return sum;
    }
}
