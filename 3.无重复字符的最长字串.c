int SearchChar(char* s, int head, int tail, char targetChar) {
    for (int i = head; i < tail; i++) {
        if (s[i] == targetChar) {
            return i;
        }
    }
    return -1;
}

int lengthOfLongestSubstring(char* s) {
    int Len = strlen(s);
    int i = 0;
    int maxLen = 1;
    int ans = 1;
    int head = 0;
    int flag = 0;
    for (i = 1; i < Len;) {
        flag = SearchChar(s, head, i, s[i]);
        if (flag == -1) { // û�ҵ���ͬ�ַ�
            ans++;  i++;
        }
        else {          // �ҵ�����ͬ�ַ�������������
            i = flag + 2;  head = i - 1;  ans = 1;
        }
        if (ans >= maxLen) {
            maxLen = ans;
        }
    }
    return Len == 0 ? 0 : maxLen;
}