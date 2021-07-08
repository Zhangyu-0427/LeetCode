void rotate(int* nums, int numsSize, int k){
    int newArr[numsSize];
    int new_k = k % numsSize;
    for(int i = 0; i < numsSize; i++)
    {
        if(i < new_k)
            newArr[i] = nums[numsSize - new_k  + i];
        else
            newArr[i] = nums[i - new_k];
    }
    for(int i = 0; i<numsSize; i++)
        nums[i] = newArr[i];

}
