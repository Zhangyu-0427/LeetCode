#include <stdio.h>
int* addToArrayForm(int* num, int numSize, int k, int* returnSize);

int main()
{
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
    //1. 计算 K 的长度 用来确定我们动态分配的数组到底要有多长
    int Ksize = 0;
    int Knum = k;
    while(Knum)
    {
        Ksize++;
        Knum /= 10;
    }

    //2. 定义X+K的数组 用来存放其数组形式
    int len = numSize > Ksize ? numSize : Ksize;
    int* retarr = (int *)malloc(sizeof(int) * (len+1));

    //3. 整合操作 next 用来判断是否需要进位
    int reti = 0;
    int Ai = numSize - 1;
    int next = 0;
    while(len)
    {
        int a = 0;

        if(Ai >= 0)
            a = num[Ai];
        int ret = a + k%10 + next;
        k /= 10;
        if(ret > 9)
        {
            retarr[reti] = ret - 10;
            next = 1;
        }
        else
        {
            retarr[reti] = ret;
            next = 0;
        }

        reti++;
        Ai--;
        len--;
    }

    //4. 逆置数组前对最后是否需要进位做判断
    int left = 0, right = 0, retSize = 0;
    if(next == 1)
    {
        retarr[reti] = 1;
        right = reti;
        retSize = reti + 1;
    }
    else
    {
        right = reti - 1;
        retSize = reti;
    }

    //5. 逆置数组
    while(left <= right)
    {
        int tmp = retarr[left];
        retarr[left] = retarr[right];
        retarr[right] = tmp;
        left++;
        right--;
    }

    //6. 返回数组长度 以及 数组的地址
    *returnSize = retSize;
    return retarr;
}
