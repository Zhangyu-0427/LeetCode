int findComplement(int num) {
    int ans = 0;
    int i = 0;
    while (num) {
        // (num & 1)----Ϊnum���������λ(0��1)
        // 1 - (num & 1)----Ϊnum���������ȡ���Ľ��
        // ���ս�� = Sum(ÿһλ���϶�������Ӧλ��������)
        ans += (1 - (num & 1)) * pow(2, i++);
        num = num >> 1;
    }
    return ans;
}