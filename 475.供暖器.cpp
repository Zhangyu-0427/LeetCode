class Solution {
public:
    bool check(int mid, vector<int>& houses, vector<int>& heaters) {
        for(int i = 0, j = 0; i < houses.size(); i ++){
            while(j < heaters.size() && abs(heaters[j] - houses[i]) > mid)
                j ++;
            if(j >= heaters.size()) return false; // 对于i号房子，在半径为mid的情况下找不到供暖器为其供暖
        }

        return true; // 对于所有房子都可以找到半径为mid供暖器为其供暖
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int l = 0, r = 1e9;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(check(mid, houses, heaters)) r =  mid;
            else l = mid + 1;
        }
        return r;
    }
};