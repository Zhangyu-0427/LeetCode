class Solution {
public:
    string toLowerCase(string s) {
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);
            }
        }

        return s;
    }
};