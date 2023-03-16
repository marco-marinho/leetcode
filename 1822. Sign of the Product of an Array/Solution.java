class Solution {
    public int arraySign(int[] nums) {
        int num_ngs = 0;
        for(int num: nums){
            if (num == 0){
                return 0;
            }
            if (num < 0){
                num_ngs+=1;
            }
        }
        if (num_ngs%2 == 0){
            return 1;
        }
        else {
            return -1;
        }
    }
}
