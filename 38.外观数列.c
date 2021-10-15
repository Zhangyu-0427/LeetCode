char* countAndSay(int n) {
    char* ans = (char*)malloc(sizeof(char) * 4500);
    char* pattern = (char*)malloc(sizeof(char) * 4500);

    ans[0] = '1';
    ans[1] = '\0';  // 利用字符构造字符串必须在结尾手动添加'\0'

    for (int i = 0; i < n - 1; i++) { // 输入n 需打印出外观数列第 n - 1 项
        int indexPattern = 0;
        for (int j = 0; ans[j]; j++) {
            int cnt = 1;
            while (ans[j + 1] && ans[j] == ans[j + 1]) {
                cnt++;
                j++;
            }
            pattern[indexPattern++] = (char)(cnt + 48); // 整型转换为字符型
            pattern[indexPattern++] = ans[j];
        }
        strcpy(ans, pattern);
        ans[indexPattern] = '\0';
    }

    return ans;
}