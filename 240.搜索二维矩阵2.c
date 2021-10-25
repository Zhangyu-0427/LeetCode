bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int i = matrixSize - 1;
    int j = 0;
    while (i >= 0 && j <= *matrixColSize - 1) {
        if (matrix[i][j] == target) {
            return true;
        }
        else if (matrix[i][j] > target) {
            i--;
        }
        else {
            j++;
        }
    }

    return false;
}