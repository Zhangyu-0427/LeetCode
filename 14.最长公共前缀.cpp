class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)  return "";

        string ans = "";
        string flag = strs[0]; // 纵向比较可能作为前缀的每个字符
        for (int len = 0; len < strs[0].size(); len++) {
            int i = 0;
            while (i < strs.size() && strs[i][len] == flag[len]) i++;
            if (i == strs.size()) ans.push_back(strs[i - 1][len]); // 满足前缀则加入
            else return ans; // 否则直接返回ans
        }
        return ans;
    }
};