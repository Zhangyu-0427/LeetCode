int maxProduct(char** words, int wordsSize) {
    int res = 0;
    int code_binary[wordsSize];
    memset(code_binary, 0, sizeof(int) * wordsSize);

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            // 不妨令 bit =  words[i][j] - 'a' 
            // 代表的是第bit + 1个小写字母出现了
            // 1 << bit是将 0001 向左移动bit位
            // 这个时候从低位开始数，第几个为1则代表第几个小写字母出现了
            // 将默认值0000按位与上 1 << (words[i][j] - 'a') 就可将
            // 默认值的第几位变为1（按位与的性质），最后的编码中也就能够
            // 反应每个小写字母是否出现了，出现了则相应的位置为1，否则为0
            // 将其作为每个字符串的一个编码 O(C) 和 O(N)的差别
            code_binary[i] |= 1 << (words[i][j] - 'a');
        }
    }

    for (int i = 0; i < wordsSize - 1; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            // 二进制码相同进行按位与(&)结果才为1，否则为0
            if (!(code_binary[i] & code_binary[j])) {
                res = fmax(strlen(words[i]) * strlen(words[j]), res);
            }
        }
    }
    return res;
}