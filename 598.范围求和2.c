int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    if (opsSize == 0) { // 没有操作时 最大的元素个数就是最开始矩阵中0的个数
        return m * n;
    }

    // 找重叠部分---找最小的行和列
    int row_min = INT_MAX, col_min = INT_MAX;
    for (int i = 0; i < opsSize; i++) {
        for (int j = 0; j < opsColSize[i]; j += 2) {
            if (ops[i][j] < row_min)
                row_min = ops[i][j];
            if (ops[i][j + 1] < col_min)
                col_min = ops[i][j + 1];
        }
    }
    return row_min * col_min;
}