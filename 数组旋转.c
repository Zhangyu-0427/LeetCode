void rotate(int* nums, int numsSize, int k){
    int  move = k%numsSize;
    int left = 0, right = numsSize - move - 1;
    //前n-k个逆置
    while(left <= right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
    left = numsSize - move, right = numsSize - 1;
    while(left <= right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
    left = 0, right = numsSize - 1;
    while(left <= right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}
