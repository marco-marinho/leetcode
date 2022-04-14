class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        k = k % len;
        if(k <= 0 || len <=1){
            return;
        }
        reverse(nums, 0, len - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, len - 1);
    }
    private void reverse(int[] nums, int start, int stop){
        while (start < stop)
        {
            int temp = nums[start];
            nums[start] = nums[stop];
            nums[stop] = temp;
            start++;
            stop--;
        }
    }
}
