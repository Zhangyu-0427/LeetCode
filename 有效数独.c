bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int row = boardSize;
    int col = *boardColSize;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] != '.')
            {
                //ÅÐ¶ÏÐÐ
                for (int row_i = 0; row_i < col; row_i++)
                {
                    if (board[i][j] == board[i][row_i] && row_i != j)
                        return false;
                }
                //ÅÐ¶ÏÁÐ
                for (int col_i = 0; col_i < row; col_i++)
                {
                    if (board[col_i][j] == board[i][j] && col_i != i)
                        return false;
                }
                //ÅÐ¶Ïzi¹¬¸ñ
                int flag_i = i / 3;//0 1 2
                int flag_j = j / 3;//0 1 2
                int number = board[i][j];
                for (int new_i = flag_i * 3; new_i < (flag_i + 1) * 3; new_i++)
                {
                    for (int new_j = flag_j * 3; new_j < (flag_j + 1) * 3; new_j++)
                    {
                        if (number == board[new_i][new_j] && new_i != i && new_j != j)
                            return false;
                    }
                }
            }
        }
    }
    return true;
}