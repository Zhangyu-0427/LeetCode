class Solution {
public:

    bool checkLeapYear(int x) {
        if( (x % 4 == 0 && x % 100 != 0) || x % 400 == 0 ) return true; // 普通闰年和世纪闰年
        return false;
    }
    int dayOfYear(string date) {
        int year = 0, mon = 0, day = 0;
        int M[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

        year = stoi(date.substr(0, 4));
        mon = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));

        int res = day;

        for(int i = 0; i < mon; i ++) res += M[i];

        if(checkLeapYear(year) && mon > 2) res += 1;

        return res;
    }
};