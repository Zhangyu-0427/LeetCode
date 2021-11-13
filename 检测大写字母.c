bool detectCapitalUse(char* word) {
    int len = strlen(word);
    int res = 0;
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (i == 0 && word[0] <= 'Z' && word[0] >= 'A') {
            flag = 1;
            res++;
        }
        else if (word[i] <= 'Z' && word[i] >= 'A') {
            res++;
        }
    }

    if (res == 1 && flag || !res || res == len) {
        return true;
    }

    return false;
}