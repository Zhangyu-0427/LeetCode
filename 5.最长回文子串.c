char* longestPalindrome(char* s) {
    int len = strlen(s);
    int res = 0;
    int begin = 0, end = 0;
    for (int i = 0; i < len; i++) {
        int l = i - 1, r = i + 1; // ��ö���������Ȼ����Ӵ�
        while (l >= 0 && r < len && s[l] == s[r]) l--, r++; // ���ű��ʽ
        if (res < r - l - 1) {
            begin = l + 1; end = r - 1; res = r - l - 1;
        }

        l = i; r = i + 1;     // ��ö��ż�����Ȼ����Ӵ�
        while (l >= 0 && r < len && s[l] == s[r]) l--, r++;
        if (res < r - l - 1) {
            begin = l + 1; end = r - 1; res = r - l - 1;
        }
    }

    if (end + 1 < len) s[end + 1] = '\0';
    return s + begin;
}