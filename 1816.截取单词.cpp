class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ') cnt++;
            if (cnt == k) return s.substr(0, i);
        }
        return s;
    }
};
// string substr(size_t pos = 0, size_t len = npos) const;
// �����Ĳ���Ϊ: posΪ��ʼλ�ÿ�ʼ��ȡ��lenΪ��Ҫ��ȡ���ַ���