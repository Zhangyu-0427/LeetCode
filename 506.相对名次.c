/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int check(int* nums, int numsSize, int x)
{
    int cnt = 1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > x) cnt++;
    }

    return cnt;
}

char* toString(int a)
{
    int tmp = a;
    char* res = malloc(sizeof(char) * 10);

    int digits = 0;
    while (tmp)
    {
        digits++;
        tmp /= 10;
    }

    int i = 0;
    for (i = 0; i < digits; i++)
    {
        res[i] = ((int)(a / pow(10, digits - i - 1)) % 10) + '0';
    }
    res[i] = '\0';
    return res;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {

    char** res = (char**)malloc(sizeof(char*) * scoreSize);
    for (int i = 0; i < scoreSize; i++)
    {
        res[i] = (char*)malloc(sizeof(char) * 100);
    }

    for (int i = 0; i < scoreSize; i++)
    {
        int rank = check(score, scoreSize, score[i]);
        if (rank == 1) strcpy(res[i], "Gold Medal\0");
        else if (rank == 2) strcpy(res[i], "Silver Medal\0");
        else if (rank == 3) strcpy(res[i], "Bronze Medal\0");
        else if (rank >= 4) strcpy(res[i], toString(rank));
    }

    *returnSize = scoreSize;
    return res;
}