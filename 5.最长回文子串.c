char* longestPalindrome(char* s) {
    int len = strlen(s);
    int res = 0;
    int begin = 0, end = 0;
    for (int i = 0; i < len; i++) {
        int l = i - 1, r = i + 1; // 先枚举奇数长度回文子串
        while (l >= 0 && r < len && s[l] == s[r]) l--, r++; // 逗号表达式
        if (res < r - l - 1) {
            begin = l + 1; end = r - 1; res = r - l - 1;
        }

        l = i; r = i + 1;     // 后枚举偶数长度回文子串
        while (l >= 0 && r < len && s[l] == s[r]) l--, r++;
        if (res < r - l - 1) {
            begin = l + 1; end = r - 1; res = r - l - 1;
        }
    }

    if (end + 1 < len) s[end + 1] = '\0';
    return s + begin;
}