class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ans;

        for(auto x: magazine) ans[x]++;
        for(auto x: ransomNote) if(--ans[x] < 0) return false;

        return true;
    }
};
