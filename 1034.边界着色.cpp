class Solution {
public:
    vector<vector<int>> visted; // 并查集
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 }; // 上、下、左、右--四个偏移量
    int n; // 行
    int m; // 列


    void dfs(vector<vector<int>>& A, int row, int col, int flag) {
        if (visted[row][col]) return; // 已访问
        if (A[row][col] != flag) return; // 不在连通分量内

        visted[row][col] = 1;
        int cnt = 0; // 记录四个方向的同色块的数量
        for (int i = 0; i < 4; i++) {
            int x = row + dx[i];
            int y = col + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m)
            {
                if (A[x][y] == 0 || A[x][y] == flag) cnt++; // 被改成0的格子，最开始也是flag色
                dfs(A, x, y, flag);
            }
        }
        if (cnt != 4) A[row][col] = 0;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n = grid.size(), m = grid[0].size(); // 行列

        visted = vector<vector<int>>(n, vector<int>(m, 0)); // n行m列并查集矩阵，初始化为0

        int flag = grid[row][col]; // 连通分量的标志色

        dfs(grid, row, col, flag); // dfs搜索边界点，找到的话将其标志成未出现的颜色'0'
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!grid[i][j]) grid[i][j] = color;

        return grid;
    }
};