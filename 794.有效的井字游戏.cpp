class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cnt_X = 0, cnt_O = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].length(); j++) {
                if (board[i][j] == 'X') cnt_X++;
                if (board[i][j] == 'O') cnt_O++;
            }
        }

        if (cnt_O > cnt_X) return false;
        if (cnt_X > cnt_O + 1) return false;
        if (check(board, 'X') && cnt_X != cnt_O + 1) return false;
        if (check(board, 'O') && cnt_X != cnt_O) return false;
        return true;
    }

    bool check(vector<string>& board, char flag) {
        int cnt = 0;
        // ÅÐ¶ÏÐÐ
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].length(); j++) {
                if (board[i][j] == flag) cnt++;
            }
            if (cnt == 3) return true;
            cnt = 0;
        }
        // ÅÐ¶ÏÁÐ
        cnt = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].length(); j++) {
                if (board[j][i] == flag) cnt++;
            }
            if (cnt == 3) return true;
            cnt = 0;
        }
        cnt = 0;
        // ÅÐ¶Ï¶Ô½ÇÏß
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].length(); j++) {
                if (i == j && board[i][j] == flag) cnt++;
            }
        }
        if (cnt == 3) return true;
        cnt = 0;
        // ÅÐ¶Ï¶Ô½ÇÏß
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].length(); j++) {
                if (i + j == 2 && board[i][j] == flag) cnt++;
            }
        }
        if (cnt == 3) return true;

        return false;
    }
};