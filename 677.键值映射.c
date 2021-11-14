typedef struct {
    char** str_s;
    int* val;
    int cnt;
} MapSum;


MapSum* mapSumCreate() {
    MapSum* ret = (MapSum*)malloc(sizeof(MapSum));
    ret->str_s = (char**)malloc(sizeof(char*) * 60);
    for (int i = 0; i < 60; i++) {
        ret->str_s[i] = (char*)malloc(sizeof(char) * 50);
    }

    ret->val = (int*)malloc(sizeof(int) * 60);
    ret->cnt = 0;
    return ret;
}

void mapSumInsert(MapSum* obj, char* key, int val) {
    int nums = obj->cnt;
    // 插入的key已存在的情况则应覆盖它
    for (int i = 0; i < obj->cnt; i++) {
        if (strcmp(obj->str_s[i], key) == 0) {
            strcpy(obj->str_s[i], key);
            obj->val[i] = val;
            return;
        }
    }
    strcpy(obj->str_s[nums], key);
    obj->val[nums] = val;

    obj->cnt++;
}

int mapSumSum(MapSum* obj, char* prefix) {
    int sum = 0;
    int j = 0;
    for (int i = 0; i < obj->cnt; i++) {

        for (j = 0; j < strlen(prefix); j++) {
            if (obj->str_s[i][j] != prefix[j])
                break;
        }
        if (j == strlen(prefix)) {
            sum += obj->val[i];
        }
    }

    return sum;
}

void mapSumFree(MapSum* obj) {
    free(obj);
}

/**
 * Your MapSum struct will be instantiated and called as such:
 * MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);

 * int param_2 = mapSumSum(obj, prefix);

 * mapSumFree(obj);
*/