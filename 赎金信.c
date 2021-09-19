bool canConstruct(char* ransomNote, char* magazine) {
    int r_len = strlen(ransomNote);
    int m_len = strlen(magazine);
    int i = 0, j = 0;
    //遍历ransomNote 在magazine中搜索 搜索到将magazine中的该字符改为'0'

    for (i = 0; i < r_len; i++)
    {
        char target = ransomNote[i];
        for (j = 0; j < m_len; j++)
        {
            if (magazine[j] == target)
            {
                magazine[j] = '/n';
                break;
            }
        }
        if (j == m_len)
        {
            return false;
        }
    }
    return true;
}