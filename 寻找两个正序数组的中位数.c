double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size == 0)
    {
        if (nums2Size % 2 == 0)
            return (nums2[nums2Size / 2] + nums2[(nums2Size / 2) - 1]) / 2.0;
        else
            return nums2[nums2Size / 2] / 1.0;
    }
    if (nums2Size == 0)
    {
        if (nums1Size % 2 == 0)
            return (nums1[nums1Size / 2] + nums1[(nums1Size / 2) - 1]) / 2.0;
        else
            return nums1[nums1Size / 2] / 1.0;
    }

    int MergwArrays[nums1Size + nums2Size];
    int p1 = 0, p2 = 0, k = 0;
    while (p1 < nums1Size && p2 < nums2Size)
    {
        if (nums1[p1] <= nums2[p2])
            MergwArrays[k++] = nums1[p1++];
        else
            MergwArrays[k++] = nums2[p2++];
    }
    if (p1 == nums1Size)
    {
        while (p2 < nums2Size)
        {
            MergwArrays[k++] = nums2[p2++];
        }
    }
    else
    {
        while (p1 < nums1Size)
        {
            MergwArrays[k++] = nums1[p1++];
        }
    }

    if ((nums1Size + nums2Size) % 2 == 0)
        return (MergwArrays[(nums1Size + nums2Size) / 2] + MergwArrays[(nums1Size + nums2Size - 2) / 2]) / 2.0;
    else
        return MergwArrays[(nums1Size + nums2Size) / 2] / 1.0;
}