int maxPower(char* s) {
    int res = 0;
    for (int i = 0; i < strlen(s); i++) {
        int j = i + 1;
        while (j < strlen(s) && s[i] == s[j]) j++;
        res = fmax(res, j - i);
        i = j - 1; // �������1�Ļ�����i++������һ���ַ�
    }

    return res;
}