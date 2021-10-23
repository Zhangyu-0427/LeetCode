/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 /* 解法--1 */

  int* constructRectangle(int area, int* returnSize){
      int* retArr = (int*)malloc(sizeof(int) * 2);
      int num = sqrt(area);
      int left = num, right = num;
      while(left <= right && left > 0 && right <= area) {
          if(left * right == area) {
              retArr[1] = left;
              retArr[0] = right;
              *returnSize = 2;
              return retArr;
          }
          else if(left * right < area){
              right++;
          }else{
              left--;
          }
      }

      *returnSize = 0;
      return retArr;
  }

 /* 解法--2 */

int* constructRectangle(int area, int* returnSize) {
    int* retArr = (int*)malloc(sizeof(int) * 2);

    for (int i = sqrt(area); i >= 1; i--) {
        if (area % i == 0) {
            retArr[0] = area / i;
            retArr[1] = i;
            *returnSize = 2;
            return retArr;
        }
    }

    *returnSize = 0;
    return retArr;
}