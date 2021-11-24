// 数学——包含排斥原理

// 找每个英文单词的特征字母
// 找到每个特征字母所代表的单词之后再考虑所含的特征字母所涉及的单词要尽可能少

// 单词     特征字母
// zero  ---- z
// two   ---- w
// four  ---- u
// six   ---- x
// eight ---- g
/*----以上单词个数已确定----*/
// three ---- h(除去eight)
// five  ---- f(除去five)
// seven ---- s(除去six)
/*----以上单词个数已确定----*/
// one   ---- o(除去zero、two、four)
// nine  ---- i(除去six、five)
// Ps:除去是因为被除去的单词数量已别确定，所以它所含的特征字母可以来反应其数量
// 至此，所有数字都被确定

char* originalDigits(char* s) {
    char* res = (char*)malloc(sizeof(char) * 15000);
    int digits[26];
    int num0_9[10];
    memset(num0_9, 0, sizeof(int) * 9);
    memset(digits, 0, sizeof(int) * 26);
    for (int i = 0; i < strlen(s); i++)
    {
        digits[s[i] - 'a']++;
    }

    num0_9[0] = digits['z' - 'a'];
    num0_9[2] = digits['w' - 'a'];
    num0_9[4] = digits['u' - 'a'];
    num0_9[6] = digits['x' - 'a'];
    num0_9[8] = digits['g' - 'a'];
    num0_9[3] = digits['h' - 'a'] - num0_9[8];
    num0_9[5] = digits['f' - 'a'] - num0_9[4];
    num0_9[7] = digits['s' - 'a'] - num0_9[6];
    num0_9[1] = digits['o' - 'a'] - num0_9[0] - num0_9[2] - num0_9[4];
    num0_9[9] = digits['i' - 'a'] - num0_9[8] - num0_9[6] - num0_9[5];

    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        while (num0_9[i] --) {
            res[cnt++] = i + '0';
        }
    }
    res[cnt++] = '\0';

    return res;
}