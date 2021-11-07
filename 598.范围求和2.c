int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    if (opsSize == 0) { // û�в���ʱ ����Ԫ�ظ��������ʼ������0�ĸ���
        return m * n;
    }

    // ���ص�����---����С���к���
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