// ��ѧ���������ų�ԭ��

// ��ÿ��Ӣ�ĵ��ʵ�������ĸ
// �ҵ�ÿ��������ĸ������ĵ���֮���ٿ���������������ĸ���漰�ĵ���Ҫ��������

// ����     ������ĸ
// zero  ---- z
// two   ---- w
// four  ---- u
// six   ---- x
// eight ---- g
/*----���ϵ��ʸ�����ȷ��----*/
// three ---- h(��ȥeight)
// five  ---- f(��ȥfive)
// seven ---- s(��ȥsix)
/*----���ϵ��ʸ�����ȷ��----*/
// one   ---- o(��ȥzero��two��four)
// nine  ---- i(��ȥsix��five)
// Ps:��ȥ����Ϊ����ȥ�ĵ��������ѱ�ȷ����������������������ĸ��������Ӧ������
// ���ˣ��������ֶ���ȷ��

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