int bit_num(int n) {
    if (n == 0) return 1;
    int res = 0;
    while (n) {
        res++;
        n /= 10;
    }

    return res;
}

char* getHint(char* secret, char* guess) {
    int len = strlen(secret);

    int cnt_A = 0;
    int cnt_B = 0;
    int num_A[10];
    int num_B[10];
    memset(num_A, 0, sizeof(int) * 10);
    memset(num_B, 0, sizeof(int) * 10);
    for (int i = 0; i < len; i++) {
        num_A[(secret[i] - '0')]++;
        num_B[(guess[i] - '0')]++;
        if (secret[i] == guess[i]) {
            cnt_A++;
            num_A[(secret[i] - '0')]--;
            num_B[(guess[i] - '0')]--;
        }
    }

    for (int i = 0; i < 10; i++) {
        cnt_B += (num_A[i] < num_B[i]) ? num_A[i] : num_B[i];
    }

    char* retArr = (char*)malloc(sizeof(char) * 1010);
    int bit_A = bit_num(cnt_A);
    int bit_B = bit_num(cnt_B);
    int tmp = bit_A;
    retArr[bit_A] = 'A';
    retArr[bit_A + bit_B + 1] = 'B';
    retArr[bit_A + bit_B + 2] = '\0';
    while (bit_A) {
        retArr[--bit_A] = (char)((cnt_A % 10) + '0');
        cnt_A /= 10;
    }

    while (bit_B) {
        retArr[tmp + bit_B] = (char)((cnt_B % 10) + '0');
        cnt_B /= 10;
        bit_B--;
    }

    return retArr;
}