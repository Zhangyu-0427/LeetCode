/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    int m[26], n[26];
    int cnt = 0;
    int* res = (int*)malloc(sizeof(int) * 30010);
    memset(n, 0, sizeof(int) * 26); //s
    memset(m, 0, sizeof(int) * 26); //p
    for (int i = 0; i < strlen(p); i++) m[p[i] - 'a']++;

    for (int i = 0; i < strlen(s); i++) {
        if (i + strlen(p) - 1 >= strlen(s)) break;
        for (int j = i; j < i + strlen(p); j++) n[s[j] - 'a']++;
        int j = 0;
        for (j = 0; j < 26; j++) {
            if (n[j] != m[j]) break;
        }
        if (j == 26) res[cnt++] = i;
        memset(n, 0, sizeof(int) * 26);
    }

    *returnSize = cnt;
    return res;
}