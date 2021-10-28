/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int searchTarget(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        }
    }

    return -1;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* retArr = (int*)malloc(sizeof(int) * nums1Size);
    *returnSize = nums1Size;

    int index = 0;
    int num = 0;
    for (int i = 0; i < nums1Size; i++) {
        num = -1;
        index = searchTarget(nums2, nums2Size, nums1[i]);
        for (int j = index + 1; j < nums2Size; j++) {
            if (nums2[j] > nums1[i]) {
                num = nums2[j];
                break;
            }
        }
        retArr[i] = num;
    }

    return retArr;
}