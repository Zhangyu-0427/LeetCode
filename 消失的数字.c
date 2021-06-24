#include <stdio.h>

/* 声明函数
@parm1 整型数组.
@parm2 最大数.
*/
int missingNumber(int* nums, int numsSize);

//主函数
int main()
{
    int arr[10] = {0,8,6,4,9,1,3,2,5,10}; /* [0,10] 中缺少数字 7*/
    /* 调用函数 */
    int ret = missingNumber(arr,10);
    printf("消失的数字为:> %d",ret);
    return 0;
}

int missingNumber(int* nums, int numsSize){
    int i = 0, x = 0;
    for( i = 0; i < numsSize; i++)
    {
        x ^= nums[i];
    }

    for(i = 0; i <= numsSize; i++)
    {
        x ^= i;
    }

    return x;
}
