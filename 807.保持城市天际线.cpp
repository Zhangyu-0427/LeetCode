class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // 预处理
        int n = grid.size(); 
        int m = grid[0].size();
        vector<int> maxR(n, 0); // 行最大
        vector<int> maxC(m, 0); // 列最大

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                maxR[i] = max(maxR[i], grid[i][j]);
                maxC[j] = max(maxC[j], grid[i][j]);
            }
        }

        int res = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                res += min(maxR[i], maxC[j]) - grid[i][j];
            }
        }

        return res;
    }
};