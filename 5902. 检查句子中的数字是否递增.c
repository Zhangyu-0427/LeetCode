bool areNumbersAscending(char* s) {
    int strLen = strlen(s);
    int i = 0;
    int a[100];
    int sum = 0, cnt = 0;
    for (i = 0; i < strLen; i++) {
        sum = 0;
        if (s[i] <= '9' && s[i] > '0') {
            // 遍历到数字字符的后一位仍旧是数字字符时
            if (i + 1 < strLen && s[i + 1] <= '9' && s[i + 1] >= '0') {
                sum += (s[i] - '0') * 10 + (s[i + 1] - '0');
                i = i + 2;
            }
            else {
                sum += s[i] - '0';
            }
            a[cnt++] = sum;
        }

    }

    for (i = 0; i < cnt - 1; i++) {
        if (a[i + 1] <= a[i]) {
            return false;
        }
    }
    return true;
}