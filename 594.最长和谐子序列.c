int cmp(const void* a, const void* b) {
    int a_ = *((int*)a);  // 返回的是：
    int b_ = *((int*)b);  // a 在 b 的前面（前者索引小）时
    return a_ - b_;       // a - b 的值作为是否需要交换 a 和 b 的依据
}

int findLHS(int* nums, int numsSize) {
    // 先排序
    qsort(nums, numsSize, sizeof(nums[0]), cmp);

    int res = 0;
    // 滑动窗口的最大值和最小值相差为1时，求其最大长度
    for (int i = 0; i < numsSize; i++) {
        int j = i + 1;
        while (j < numsSize) {
            if (j < numsSize && nums[j] == nums[i]) j++;
            else if (j < numsSize && nums[j] == nums[i] + 1) {
                res = fmax(j - i + 1, res);
                j++;
            }
            else break;
        }
    }
    return res;
}