typedef long long LL;

class Solution {
public:
    const int mod = 1337;

    LL mypow(int a, int b)
    {
        if (!b) return 1;
        if (b == 1) return a % mod;
        return (mypow(a, b / 2) * mypow(a, b / 2) * mypow(a, b % 2)) % mod;
    }
    int superPow(int a, vector<int>& b) {
        if (b.size() == 0) return 1;
        int last = b.back();
        b.pop_back();

        return (mypow(superPow(a, b), 10) * mypow(a, last)) % mod;
    }
};
// �ֽ���,����132^2435�η�
// ����132^2435 = 132^(243 * 10 + 5) �ȷֽ��(132^243) ^ 10 * 132^5
// Ȼ����132^243 = 132^(24) ^ 10 * 132^3
// ����132^24 = 132^(2) ^ 10 * 132 ^ 4