/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int first = 0;
    int second = first + 1;
    int last_num = numbers[first];
    while(numbers[first] + numbers[second] != target){
        second++;
        if(second==numbersSize){
            first++;
            while(numbers[first] == last_num) {
                first++;
            }
            last_num = numbers[first];
            second = first + 1;
        }
    }
    int* ret = malloc(sizeof(int)*2);
    ret[0] = first + 1;
    ret[1] = second + 1;
    *returnSize = 2;
    return ret;
}
