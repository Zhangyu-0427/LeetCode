class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        array<int, 26> t{};
        for(auto ch : licensePlate){
            if(isalpha(ch)){
                t[tolower(ch) - 'a'] ++;
            }
        }

        int index = -1;
        for(int i = 0; i < words.size(); i ++){
            array<int, 26> c{};
            for(auto ch : words[i]){
                c[ch - 'a'] ++;
            }

            int flag = 1; // 是补全词
            for(int j = 0; j < 26; j ++){
                if(c[j] < t[j]){
                    flag = 0;
                    break;
                }
            }

            if(flag && (index < 0 || words[i].length() < words[index].length()))
                index = i;
        }

        return words[index];
    }
};