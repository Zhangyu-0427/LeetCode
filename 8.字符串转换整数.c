int myAtoi(char* s) {
    int i = 0;
    int signFlag = 1; // 默认为正
    int num[200];
    int cnt = 0; // 记录数字字符的个数
    int Len = strlen(s);
    int leadingCnt = 0;
    // 1. 丢弃无用的前导空格
    while (i < Len && s[i] == ' ') {
        i++;
    }

    // 2. 读取整数的符号(如果有)
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

    // 处理余下的字符
    while (i < Len && s[i] <= '9' && s[i] >= '0') {
        num[cnt++] = (int)(s[i] - '0');
        i++;
    }

    //  第一个有效字符为非数字字符时
    if (cnt == 0) {
        return 0;
    }

    // 整数转换

    int validDigit = 0;
    int leadingZeroFlag = 1;
    int newHead = 0;
    long int sum = 0;
    if (num[0] == 0) {
        leadingZeroFlag = 1; // 有前导零
    }
    for (i = 0; i < cnt; i++) {
        if (num[i] == 0 && leadingZeroFlag) {
            continue;
        }
        leadingZeroFlag = 0; // 前导零被消除
        validDigit++; // 纪录有效位数
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

    sum *= signFlag; // 确定最终整数的值

    if (sum > 2147483647) {
        return 2147483647;
    }
    if (sum < -2147483648) {
        return -2147483648;
    }

    return sum;
}