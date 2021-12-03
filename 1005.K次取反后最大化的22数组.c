int cmp(const void* a, const void* b) {
    int a_ = *((int*)a);
    int b_ = *((int*)b);

    return a_ - b_;
}

int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(nums[0]), cmp);

    int res = 0;
    for (int i = 0; i < numsSize && k > 0; i++) {
        if (nums[i] < 0) nums[i] = -nums[i], k--;
        else break;
    }

    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    if (k % 2 == 1) nums[0] = -nums[0];

    for (int i = 0; i < numsSize; i++) res += nums[i];

    return res;
}

