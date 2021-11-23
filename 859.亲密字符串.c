bool buddyStrings(char* s, char* goal) {

    if (strlen(s) != strlen(goal)) return false;

    int digit_s[26]; memset(digit_s, 0, sizeof(int) * 26);
    int digit_goal[26]; memset(digit_goal, 0, sizeof(int) * 26);
    // 统计每个字符串中的字符出现的次数
    for (int i = 0; i < strlen(s); i++) {
        digit_s[s[i] - 'a']++; digit_goal[goal[i] - 'a']++;
    }

    // 如果词频不一样，则一定不会是亲密字符串
    for (int i = 0; i < 26; i++) {
        if (digit_s[i] != digit_goal[i]) return false;
    }

    if (strcmp(s, goal) == 0) {
        // 字符串相等
        for (int i = 0; i < 26; i++) {
            // 存在一个字符常出现多次
            if (digit_s[i] > 1) return true;
        }
        return false;
    }

    // 词频一样、字符串不相等
    // 找出字符不相等的两个位置 _i 和 _j
    int _i = -1, _j = -1, cnt = 0;
    for (int i = 0; i < strlen(s) && cnt <= 2; i++) {
        if (s[i] != goal[i]) {
            cnt++;
            if (cnt == 1) _i = i;
            if (cnt == 2) _j = i;
        }
    }

    // 只允许交换一次
    char tmp = s[_i];
    s[_i] = s[_j];
    s[_j] = tmp;

    if (strcmp(s, goal) == 0) return true;
    return false;
}