class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        int x = m + n - 2;
        int y = min(m - 1, n - 1);
        vector<bool> flag(y + 1, true);
        for (int i = x; i >= x - y + 1; i -- ) {
            res *= i;
            for (int j = 1; j <= y; j ++ ) {
                if (flag[j] && res % j == 0) {
                    res /= j;
                    flag[j] = false;
                }
            }
        }
        return static_cast<int>(res);
    }
};
