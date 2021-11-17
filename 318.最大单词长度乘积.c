int maxProduct(char** words, int wordsSize) {
    int res = 0;
    int code_binary[wordsSize];
    memset(code_binary, 0, sizeof(int) * wordsSize);

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            // ������ bit =  words[i][j] - 'a' 
            // ������ǵ�bit + 1��Сд��ĸ������
            // 1 << bit�ǽ� 0001 �����ƶ�bitλ
            // ���ʱ��ӵ�λ��ʼ�����ڼ���Ϊ1�����ڼ���Сд��ĸ������
            // ��Ĭ��ֵ0000��λ���� 1 << (words[i][j] - 'a') �Ϳɽ�
            // Ĭ��ֵ�ĵڼ�λ��Ϊ1����λ������ʣ������ı�����Ҳ���ܹ�
            // ��Ӧÿ��Сд��ĸ�Ƿ�����ˣ�����������Ӧ��λ��Ϊ1������Ϊ0
            // ������Ϊÿ���ַ�����һ������ O(C) �� O(N)�Ĳ��
            code_binary[i] |= 1 << (words[i][j] - 'a');
        }
    }

    for (int i = 0; i < wordsSize - 1; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            // ����������ͬ���а�λ��(&)�����Ϊ1������Ϊ0
            if (!(code_binary[i] & code_binary[j])) {
                res = fmax(strlen(words[i]) * strlen(words[j]), res);
            }
        }
    }
    return res;
}