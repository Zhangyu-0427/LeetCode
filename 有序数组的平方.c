/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;

    for(int i = 0, j = numsSize - 1, pos = numsSize - 1; i<=j;)
    {
        if(nums[i] * nums[i] < nums[j] * nums[j])
        {
            ans[pos] = nums[j] * nums[j];
            j--;
        }
        else
        {
            ans[pos] = nums[i] * nums[i];
            i++;
        }
        pos--;
    }

    return ans;
}
