bool isAnagram(char* s, char* t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    int arr1[26] = { 0 };
    int arr2[26] = { 0 };

    for (int i = 0; i < s_len; i++)
    {
        arr1[s[i] - 'a']++;
    }
    for (int i = 0; i < t_len; i++)
    {
        arr2[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}