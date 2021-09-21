int len = strlen(s);
int newlen = len;
int last_word_len = 0;
for (int i = len - 1; i >= 0; i--)
{
    if (s[i] == ' ')
    {
        newlen--;
        continue;
    }
    break;
}
for (int i = newlen - 1; i >= 0; i--)
{
    if (s[i] == ' ')
        break;
    last_word_len++;
}
return last_word_len;