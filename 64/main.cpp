class Solution {
public:
    int minPathSum(vector<vector<int>> grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                int x = i - 1;
                int y = j - 1;
                if (x >= 0 && y >= 0) {
                    dp[i][j] = min(dp[x][j], dp[i][y]) + grid[i][j];
                } else if (y >= 0) {
                    dp[i][j] = dp[i][y] + grid[i][j];
                } else if (x >= 0) {
                    dp[i][j] = dp[x][j] + grid[i][j];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
