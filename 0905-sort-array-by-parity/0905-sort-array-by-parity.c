/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int* sortArrayByParity(int* nums, int numsSize, int* returnSize) { 
    for(int i=0;i<numsSize-1;i++){
        for(int j=0;j<numsSize-1;j++){
            if(nums[j]%2!=0 && nums[j+1]%2==0){
                int temp = nums[j];
                nums[j]= nums[j+1];
                nums[j+1]= temp;
                j++;
            }
        }
    }
    *returnSize = numsSize;
    return nums;
}