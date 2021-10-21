/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int assertFullNine(int* digits, int size) {
    for (int i = 0; i < size; i++) {
        if (digits[i] != 9) {
            return 0; // ����Ҫ����λ��
        }
    }
    return 1; // ��������Ԫ��ȫΪ����9--��Ҫ����λ��
}
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* retArr = NULL;
    if (assertFullNine(digits, digitsSize)) {
        retArr = (int*)malloc(sizeof(int) * (digitsSize + 1)); // ���ǽ�λ���

        retArr[0] = 1;
        for (int i = 1; i < digitsSize + 1; i++) {
            retArr[i] = 0;
        }

        *returnSize = digitsSize + 1;
        return retArr;
    }
    else {
        retArr = (int*)malloc(sizeof(int) * digitsSize); // �����ǽ�λ���
        *returnSize = digitsSize;
    }

    int digit = 0;
    int flagOfCarry = 0; // Ĭ�ϸ�λ����Ҫ��λ��
    for (int i = digitsSize - 1; i >= 0; i--) {

        if (i == digitsSize - 1) {
            digit = digits[i] + 1; // ��ȡ��һ֮����������һλ��ֵ

            if (digit == 10) {
                flagOfCarry = 1;
                retArr[i] = 0;
            }
            else {
                flagOfCarry = 0;
                retArr[i] = digit;
            }
            continue;
        }

        digit = digits[i] + 1 * flagOfCarry;
        if (digit == 10) {
            flagOfCarry = 1;
        }
        else {
            flagOfCarry = 0;
        }

        if (flagOfCarry == 1) {
            retArr[i] = 0;
        }
        else {
            retArr[i] = digit;
        }
    }

    return retArr;
}