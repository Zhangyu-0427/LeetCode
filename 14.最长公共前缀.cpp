class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)  return "";

        string ans = "";
        string flag = strs[0]; // ����ȽϿ�����Ϊǰ׺��ÿ���ַ�
        for (int len = 0; len < strs[0].size(); len++) {
            int i = 0;
            while (i < strs.size() && strs[i][len] == flag[len]) i++;
            if (i == strs.size()) ans.push_back(strs[i - 1][len]); // ����ǰ׺�����
            else return ans; // ����ֱ�ӷ���ans
        }
        return ans;
    }
};