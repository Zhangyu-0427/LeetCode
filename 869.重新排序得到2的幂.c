int match(int num, int pow_2) {
    int a[10];
    int b[10];
    memset(a, 0, sizeof(int) * 10);
    memset(b, 0, sizeof(int) * 10);

    while (num) {
        a[num % 10] ++;
        num /= 10;
    }
    while (pow_2) {
        b[pow_2 % 10] ++;
        pow_2 /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

bool reorderedPowerOf2(int n) {
    for (int i = 0; i < 31; i++) { // 2^30 > 10^9 
        int pow_2 = (int)pow(2, i);
        if (match(n, pow_2)) {
            return true;
        }
    }
    return false;
}