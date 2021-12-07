class Solution {
public:
    vector<vector<int>> visted; // ���鼯
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 }; // �ϡ��¡�����--�ĸ�ƫ����
    int n; // ��
    int m; // ��


    void dfs(vector<vector<int>>& A, int row, int col, int flag) {
        if (visted[row][col]) return; // �ѷ���
        if (A[row][col] != flag) return; // ������ͨ������

        visted[row][col] = 1;
        int cnt = 0; // ��¼�ĸ������ͬɫ�������
        for (int i = 0; i < 4; i++) {
            int x = row + dx[i];
            int y = col + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m)
            {
                if (A[x][y] == 0 || A[x][y] == flag) cnt++; // ���ĳ�0�ĸ��ӣ��ʼҲ��flagɫ
                dfs(A, x, y, flag);
            }
        }
        if (cnt != 4) A[row][col] = 0;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n = grid.size(), m = grid[0].size(); // ����

        visted = vector<vector<int>>(n, vector<int>(m, 0)); // n��m�в��鼯���󣬳�ʼ��Ϊ0

        int flag = grid[row][col]; // ��ͨ�����ı�־ɫ

        dfs(grid, row, col, flag); // dfs�����߽�㣬�ҵ��Ļ������־��δ���ֵ���ɫ'0'
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!grid[i][j]) grid[i][j] = color;

        return grid;
    }
};