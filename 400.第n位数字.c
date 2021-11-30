int findNthDigit(int n) {
    long int k = 1, s = 9, t = 1;
    while (n > k * s) {
        n -= k * s;
        k++, s *= 10, t *= 10;
    }
    t += (n + k - 1) / k - 1;
    n = n % k ? n % k : k;

    // 数字t的从低位到高位顺序的第k - n + 1个数是多少
    // 数字t的从高位到低位顺序的第n个数多少
    return (int)(t / (int)pow(10, k - n)) % 10;
}