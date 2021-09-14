#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int maxSubArray(int* nums, int numsSize);
int main()
{
    int tmp_arr[10] = {-1, 2, 5, -4, 6, 7, 0, 5, -6, 4};
    int max = maxSubArray(tmp_arr, 10);
    printf("最大连续子序列的和为:%d\n", max);
}
int maxSubArray(int* nums, int numsSize) {
    int pre = 0, Max_record = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        pre = fmax(nums[i] + pre, nums[i]);
        Max_record = fmax(pre, Max_record);
    }
    return Max_record;
}