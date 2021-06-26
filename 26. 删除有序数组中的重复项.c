int removeDuplicates(int* nums, int numsSize){
    int prev = 0, cur = 1, dst = 0;
    //边界考虑
    if(numsSize == 0 || numsSize == 1)
    {
        return numsSize;
    }
    //算法实现
    else
    {
        while(cur < numsSize)
        {
            if(nums[prev] != nums[cur])
            {
                nums[dst] = nums[prev];
                dst++;
            }
            prev++;
            cur++;
        }
        nums[dst] = nums[numsSize-1];
    }
    return dst+1;
}
