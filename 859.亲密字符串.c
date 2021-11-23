bool buddyStrings(char* s, char* goal) {

    if (strlen(s) != strlen(goal)) return false;

    int digit_s[26]; memset(digit_s, 0, sizeof(int) * 26);
    int digit_goal[26]; memset(digit_goal, 0, sizeof(int) * 26);
    // ͳ��ÿ���ַ����е��ַ����ֵĴ���
    for (int i = 0; i < strlen(s); i++) {
        digit_s[s[i] - 'a']++; digit_goal[goal[i] - 'a']++;
    }

    // �����Ƶ��һ������һ�������������ַ���
    for (int i = 0; i < 26; i++) {
        if (digit_s[i] != digit_goal[i]) return false;
    }

    if (strcmp(s, goal) == 0) {
        // �ַ������
        for (int i = 0; i < 26; i++) {
            // ����һ���ַ������ֶ��
            if (digit_s[i] > 1) return true;
        }
        return false;
    }

    // ��Ƶһ�����ַ��������
    // �ҳ��ַ�����ȵ�����λ�� _i �� _j
    int _i = -1, _j = -1, cnt = 0;
    for (int i = 0; i < strlen(s) && cnt <= 2; i++) {
        if (s[i] != goal[i]) {
            cnt++;
            if (cnt == 1) _i = i;
            if (cnt == 2) _j = i;
        }
    }

    // ֻ������һ��
    char tmp = s[_i];
    s[_i] = s[_j];
    s[_j] = tmp;

    if (strcmp(s, goal) == 0) return true;
    return false;
}