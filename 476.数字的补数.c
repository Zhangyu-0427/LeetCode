int findComplement(int num) {
    int ans = 0;
    int i = 0;
    while (num) {
        // (num & 1)----为num二进制最低位(0、1)
        // 1 - (num & 1)----为num二进制最低取反的结果
        // 最终结果 = Sum(每一位乘上二进制相应位的数量级)
        ans += (1 - (num & 1)) * pow(2, i++);
        num = num >> 1;
    }
    return ans;
}