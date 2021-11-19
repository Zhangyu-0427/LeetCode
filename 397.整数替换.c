
// -------------说明----------------------

// 处理n + 1时，根据所给出的数据范围，当 n = 2^31 - 1时，n + 1会爆 int
// 我们知道 n 为奇数时+1或者-1都可以将其变为偶数，而对于偶数我们只能进行
// 折半，故我们把这两个操作归在一起.即对于奇数时，我们将其变为 n - 1 / 2 
// 和 n + 1 / 2，在计算这两个时，我们可以巧妙的利用整数除法的下取整来防止爆int:
// (n / 2) == ( (n - 1) / 2 )  and ( (n / 2) + 1 ) == ( (n + 1) / 2 )

int integerReplacement(int n) {
    // 1. 贪心 --- 递归

    //if(n == 1) return 0;
    //if(n & 1) return 2 + fmin(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    //else return 1 + integerReplacement(n / 2);

    // 2. 贪心 --- 非递归 --- 不好想

    long m = n;
    int res = 0;

    while (m != 1)
    {
        if (m & 1) // m为奇数
        {
            if ((m & 2) && m != 3) // m二进制从最低位开始至少有两个连续的1且m大于3
            {
                m += 1;
            }
            else
            {
                m -= 1;
            }
        }
        else
        {
            m >>= 1;
        }
        res++;
    }
    return res;
}