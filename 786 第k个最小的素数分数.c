/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int a, b;
double max;
int check(int* arr, int size, double mid) {
    max = 0;
    int res = 0;
    for (int i = 0, j = 1; j < size; j++) {
        while (arr[i] * 1.0 / arr[j] < mid) i++;

        res += i;
        for (int l = 0; l < i; l++) {
            if (arr[l] * 1.0 / arr[j] > max) {
                a = arr[l], b = arr[j], max = arr[l] * 1.0 / arr[j];
            }
        }
    }
    return res;
}
int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize) {
    max = 0;
    a = b = 0;
    double l = 0, r = 1.0;

    while (1) {
        double mid = (l + r) / 2;
        int cnt = check(arr, arrSize, mid); // �õ���midС�����ж��ٸ�
        if (cnt < k) l = mid;
        else if (cnt > k) r = mid; // ע�����ﲻ�ܶ�l = mid + 1 �� r = mid - 1.��Ϊmid��һ������0��1֮���ʵ��
        else break;
    }
    int* ans = (int*)malloc(sizeof(int) * 2);
    ans[0] = a, ans[1] = b;
    *returnSize = 2;
    return ans;
}