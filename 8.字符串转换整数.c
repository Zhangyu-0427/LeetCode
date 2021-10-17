int myAtoi(char* s) {
    int i = 0;
    int signFlag = 1; // Ĭ��Ϊ��
    int num[200];
    int cnt = 0; // ��¼�����ַ��ĸ���
    int Len = strlen(s);
    int leadingCnt = 0;
    // 1. �������õ�ǰ���ո�
    while (i < Len && s[i] == ' ') {
        i++;
    }

    // 2. ��ȡ�����ķ���(�����)
    while (i < Len && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '+') {
            signFlag = 1;
            i++;
            leadingCnt++;
        }
        else {
            signFlag = -1;
            i++;
            leadingCnt++;
        }
    }
    if (leadingCnt > 1) {
        return 0;
    }

    // �������µ��ַ�
    while (i < Len && s[i] <= '9' && s[i] >= '0') {
        num[cnt++] = (int)(s[i] - '0');
        i++;
    }

    //  ��һ����Ч�ַ�Ϊ�������ַ�ʱ
    if (cnt == 0) {
        return 0;
    }

    // ����ת��

    int validDigit = 0;
    int leadingZeroFlag = 1;
    int newHead = 0;
    long int sum = 0;
    if (num[0] == 0) {
        leadingZeroFlag = 1; // ��ǰ����
    }
    for (i = 0; i < cnt; i++) {
        if (num[i] == 0 && leadingZeroFlag) {
            continue;
        }
        leadingZeroFlag = 0; // ǰ���㱻����
        validDigit++; // ��¼��Чλ��
    }
    if (validDigit >= 11) {
        if (signFlag == 1) {
            return 2147483647;
        }
        else {
            return -2147483648;
        }
    }
    newHead = cnt - validDigit;
    for (i = newHead; i < cnt; i++) {
        sum += num[i] * pow(10, --validDigit);
    }

    sum *= signFlag; // ȷ������������ֵ

    if (sum > 2147483647) {
        return 2147483647;
    }
    if (sum < -2147483648) {
        return -2147483648;
    }

    return sum;
}