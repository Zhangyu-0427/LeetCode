int distributeCandies(int* candyType, int candyTypeSize) {

    int flag_a[200010];
    int cnt = 0;
    memset(flag_a, 0, sizeof(int) * 200010);
    for (int i = 0; i < candyTypeSize; i++) {
        candyType[i] += 100000;
        flag_a[candyType[i]]++;
    }

    for (int i = 0; i < 200010; i++) {
        if (flag_a[i]) {
            cnt++;
        }
    }

    // 贪心
    // 1. 糖果种类数大于我应获得的糖果数量，则我可以获得的最大糖果种类数为应得得糖果数量
    if (cnt >= candyTypeSize / 2) {
        return candyTypeSize / 2;
    }
    // 2。 糖果种类数小于我应得得糖果数量，则我可以获得的最大糖果种类数为糖果种类数
    return cnt;
}