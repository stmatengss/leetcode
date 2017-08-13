class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) {
            return 0;
        }
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        res[0][0] = 1;
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                if (obstacleGrid[i][j] == 1)
                    continue;
                int x = i - 1;
                int y = j - 1;
                if (x >= 0 ) {
                    res[i][j] += res[x][j];
                }
                if (y >= 0 ) {
                    res[i][j] += res[i][y];
                } 
            }
        }
        return res[n - 1][m - 1];
    }
};
