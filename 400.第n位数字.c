int findNthDigit(int n) {
    long int k = 1, s = 9, t = 1;
    while (n > k * s) {
        n -= k * s;
        k++, s *= 10, t *= 10;
    }
    t += (n + k - 1) / k - 1;
    n = n % k ? n % k : k;

    // ����t�Ĵӵ�λ����λ˳��ĵ�k - n + 1�����Ƕ���
    // ����t�ĴӸ�λ����λ˳��ĵ�n��������
    return (int)(t / (int)pow(10, k - n)) % 10;
}