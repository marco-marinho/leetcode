class Solution {
    public int[] sortedSquares(int[] nums) {
        int len = nums.length;
        int[] output = new int[len];
        int pos_idx = 0;
        for(int num : nums){
            if(num < 0){
                pos_idx++;
            }
        }
        int negative_idx = pos_idx - 1;
        int cur_idx = 0;
        int cur_pos = Integer.MAX_VALUE;
        int cur_neg = -Integer.MAX_VALUE;
        if (pos_idx < len){
            cur_pos = nums[pos_idx];
        }
        if (negative_idx >= 0){
            cur_neg = nums[negative_idx];
        }
        while (cur_idx < len) {
            if (cur_pos > -1 * cur_neg) {
                output[cur_idx] = cur_neg * cur_neg;
                negative_idx--;
                if (negative_idx >= 0){
                    cur_neg = nums[negative_idx];
                }
                else{
                    cur_neg = -Integer.MAX_VALUE;
                }
            } else {
                output[cur_idx] = cur_pos * cur_pos;
                pos_idx++;
                if (pos_idx < len){
                    cur_pos = nums[pos_idx];
                }
                else{
                    cur_pos = Integer.MAX_VALUE;
                }
            }
            cur_idx++;
        }
        return output;
    }
}
