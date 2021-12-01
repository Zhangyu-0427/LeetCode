int maxPower(char* s) {
    int res = 0;
    for (int i = 0; i < strlen(s); i++) {
        int j = i + 1;
        while (j < strlen(s) && s[i] == s[j]) j++;
        res = fmax(res, j - i);
        i = j - 1; // 如果不减1的话，经i++会少算一个字符
    }

    return res;
}