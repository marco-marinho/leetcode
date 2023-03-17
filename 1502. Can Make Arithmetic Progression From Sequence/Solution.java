class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        Arrays.sort(arr);
        int dif = arr[0] - arr[1];
        for(int idx = 1; idx < arr.length - 1; idx++){
            if(arr[idx] - arr[idx+1] != dif){
                return false;
            }
        }
        return true;
    }
}