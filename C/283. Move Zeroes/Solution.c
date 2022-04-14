void moveZeroes(int* nums, int numsSize){
    int num_zeros = 0;
    int idx_to_insert = 0;
    int idx = 0;
    while(num_zeros + idx_to_insert < numsSize){
        if(nums[idx] != 0){
            nums[idx_to_insert] = nums[idx];
            idx_to_insert ++;
        }
        else{
            num_zeros++;
        }
        idx++;
    }
    while(idx_to_insert < numsSize){
        nums[idx_to_insert] = 0;
        idx_to_insert++;
    }
}
