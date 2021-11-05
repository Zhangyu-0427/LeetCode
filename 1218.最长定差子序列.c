int longestSubsequence(int* arr, int arrSize, int difference) {
    int dp[40001];
    memset(dp, 0, sizeof(int) * 40001);
    int res = 0;
    for (int i = 0; i < arrSize; i++) {
        dp[arr[i] + 20000] = dp[arr[i] + 20000 - difference] + 1;
        res = (res < dp[arr[i] + 20000]) ? dp[arr[i] + 20000] : res;
    }
    return res;
}