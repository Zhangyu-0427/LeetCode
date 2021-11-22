typedef struct {
    int* Source; // ԭ����
    int* chaos;  // �����ҵ�����
    int size;    // ��������Ĵ�СӦ��һ�£���Ϊsize
} Solution;

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
Solution* solutionCreate(int* nums, int numsSize) {
    Solution* res = (Solution*)malloc(sizeof(Solution));
    res->size = numsSize;
    res->Source = (int*)malloc(sizeof(int) * numsSize);
    res->chaos = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        res->Source[i] = nums[i];
        res->chaos[i] = nums[i];
    }

    return res;
}

int* solutionReset(Solution* obj, int* retSize) {
    for (int i = 0; i < obj->size; i++) obj->chaos[i] = obj->Source[i];
    *retSize = obj->size;

    return obj->chaos;
}

int* solutionShuffle(Solution* obj, int* retSize) {
    // ϴ���㷨
    // ������n��Ԫ�ص�����
    // 1. ����[0, n - 1]һ��֮����������������Ϊһ��������Ԫ�ص��±�
    // 2. ����Ԫ����n - 1λ�ã���ǰ��������һ��Ԫ�أ���Ԫ�ؽ��н���
    // 3. n�Լ�1
    // .........
    // �ظ�1��2��3

    // ����һ
    // int i = obj->size;
    // while(i > 0)
    // {
    //     int index = rand() % i;
    //     swap(&(obj->chaos[i - 1]), &(obj->chaos[index]));
    //     i--;
    // }

    // ������
    for (int i = obj->size - 1; i > 0; i--) {
        swap(&(obj->chaos[i]), &(obj->chaos[rand() % (i + 1)]));
    }

    *retSize = obj->size;
    return obj->chaos;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);

 * int* param_2 = solutionShuffle(obj, retSize);

 * solutionFree(obj);
*/