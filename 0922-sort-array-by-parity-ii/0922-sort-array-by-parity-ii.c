/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    int j = 1;
    int* arr = (int*)malloc(numsSize * sizeof(int));
    for (int k = 0; k < numsSize; k++) {
        if (nums[k] % 2 == 0) {
            arr[i] = nums[k];
            i += 2;
        } else {
            arr[j] = nums[k];
            j += 2;
        }
    }
    *returnSize = numsSize;
    return arr;
}