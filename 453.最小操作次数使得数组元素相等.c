int minValIndex(int* nums, int numsSize) { // 在数组中找出最小值元素的索引
    int minVal = nums[0];
    int Index = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] <= minVal) {
            minVal = nums[i];
            Index = i;
        }
    }
    return Index;
}

int minMoves(int* nums, int numsSize) {
    int minIndex = minValIndex(nums, numsSize);
    int minCnt = 0;

    for (int i = 0; i < numsSize; i++) {
        minCnt += nums[i] - nums[minIndex];
    }
    return minCnt;
}