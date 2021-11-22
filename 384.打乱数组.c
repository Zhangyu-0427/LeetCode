typedef struct {
    int* Source; // 原数组
    int* chaos;  // 被打乱的数组
    int size;    // 两个数组的大小应该一致，都为size
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
    // 洗牌算法
    // 假设有n个元素的数组
    // 1. 产生[0, n - 1]一个之间的随机数，将其作为一个待排序元素的下标
    // 2. 将该元素与n - 1位置（当前数组的最后一个元素）的元素进行交换
    // 3. n自减1
    // .........
    // 重复1、2、3

    // 方法一
    // int i = obj->size;
    // while(i > 0)
    // {
    //     int index = rand() % i;
    //     swap(&(obj->chaos[i - 1]), &(obj->chaos[index]));
    //     i--;
    // }

    // 方法二
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