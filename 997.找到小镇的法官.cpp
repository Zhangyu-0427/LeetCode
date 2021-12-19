class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> In(n + 1); // 记录入度
        vector<int> Ou(n + 1); // 记录出度

        for(auto &edge : trust)
        {
            In[edge[1]] ++, Ou[edge[0]] ++;
        }

        for(int i = 1; i <= n; i ++)
            if(In[i] == n - 1 && !Ou[i]) return i;
        
        return -1;
    }
};