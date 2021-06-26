void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if(m == 0)
    {
        memcpy(nums1,nums2,sizeof(int) * n);
        return;
    }
    if(n == 0)
    {
        return;
    }
    int* arr = (int *)malloc(sizeof(int) * (m+n));
    int i1 =0, i2 = 0, i = 0, j = 0;

    while(i1 <= m-1 && i2 <= n-1)
    {
        if(nums1[i1] <= nums2[i2])
        {
            arr[j] = nums1[i1];
            i1++;
        }
        else
        {
            arr[j] = nums2[i2];
            i2++;
        }
        j++;
    }
//注意这里判断条件不要写i1 == m 和 i2 == n
//因为这样写的话 在i1 == m的情况下 i2会++到与n相等
//进而下面的判断条件又为真 将nums1 中的无效元素添加到arr中
//注意最开始的条件i1 == m
//如果i2 == n则不会出现这样的问题
   if(i2 < n)
    {
        for(i = j; i<n+m; i++)
            arr[i] = nums2[i2++];
    }
    if(i1 < m)
    {
        for(i = j; i<m+n; i++)
            arr[i] = nums1[i1++];
    }

    for(i = 0; i<m+n; i++)
        nums1[i] = arr[i];
    free(arr);
}
