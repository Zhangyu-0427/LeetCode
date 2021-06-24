#include <stdio.h>
#include <stdlib.h>
int* singleNumber(int* nums, int numsSize);
int main()
{
    int arr[10] = {5,5,7,9,6,6,-1,-1,3,3};
    int * tmp = (int *)malloc(sizeof(int) * 2);
    tmp = singleNumber(arr,10);
    printf("%d %d",tmp[0],tmp[1]);
    return 0;
}
int* singleNumber(int* nums, int numsSize){
    int i, res = 0, xorRes = 0, pos = 0;
    int *resArr = (int *)malloc(sizeof(int) * 2);

    //异或 - 得到两个只出现一次的元素的异或值
    for(i = 0; i < numsSize; i++) xorRes ^= nums[i];
    //从右到左找到xorRes第一个为1的位置
    while(((xorRes >> pos) & 1) != 1) pos++;
    //在nums中查找在相同位置上位1的数，并累计异或，保证这个数只出现一次 a ^ a ^ b = b
    for(i = 0; i < numsSize; i++){
        if((nums[i] >> pos) & 1) res ^= nums[i];
    }
    resArr[0] = res;
    resArr[1] = xorRes ^ res;
    return resArr;
}
