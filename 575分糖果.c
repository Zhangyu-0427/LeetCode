int distributeCandies(int* candyType, int candyTypeSize) {

    int flag_a[200010];
    int cnt = 0;
    memset(flag_a, 0, sizeof(int) * 200010);
    for (int i = 0; i < candyTypeSize; i++) {
        candyType[i] += 100000;
        flag_a[candyType[i]]++;
    }

    for (int i = 0; i < 200010; i++) {
        if (flag_a[i]) {
            cnt++;
        }
    }

    // ̰��
    // 1. �ǹ�������������Ӧ��õ��ǹ����������ҿ��Ի�õ�����ǹ�������ΪӦ�õ��ǹ�����
    if (cnt >= candyTypeSize / 2) {
        return candyTypeSize / 2;
    }
    // 2�� �ǹ�������С����Ӧ�õ��ǹ����������ҿ��Ի�õ�����ǹ�������Ϊ�ǹ�������
    return cnt;
}