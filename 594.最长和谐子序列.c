int cmp(const void* a, const void* b) {
    int a_ = *((int*)a);  // ���ص��ǣ�
    int b_ = *((int*)b);  // a �� b ��ǰ�棨ǰ������С��ʱ
    return a_ - b_;       // a - b ��ֵ��Ϊ�Ƿ���Ҫ���� a �� b ������
}

int findLHS(int* nums, int numsSize) {
    // ������
    qsort(nums, numsSize, sizeof(nums[0]), cmp);

    int res = 0;
    // �������ڵ����ֵ����Сֵ���Ϊ1ʱ��������󳤶�
    for (int i = 0; i < numsSize; i++) {
        int j = i + 1;
        while (j < numsSize) {
            if (j < numsSize && nums[j] == nums[i]) j++;
            else if (j < numsSize && nums[j] == nums[i] + 1) {
                res = fmax(j - i + 1, res);
                j++;
            }
            else break;
        }
    }
    return res;
}