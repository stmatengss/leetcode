class Solution {

	public:
		vector<vector<int>> generateMatrix(int n) {

			vector<vector<int>> res(n, vector<int>(n));
			if (n == 0) 
				return res;
			for (int i = 0; i < n; i ++ ) {

				res[0][i] = i + 1;
			}
			int num = n + 1;
			int round = n - 1;
			int bias_x = 1, bias_y = 1;
			int st = 0;
			while (round) {

				st ++;
				if (st % 2) {

					for (int i = 0; i < round; i ++ ) {

						res[bias_x + i][n - bias_x] = num ++;
					}
					for (int i = 0; i < round; i ++ ) {

						res[n - bias_x][n - i - bias_x - 1] = num ++;
					}
					bias_x ++;
				} else {

					for (int i = 0; i < round; i ++ ) {

						res[n - i - bias_y - 1][bias_y - 1] = num ++;
					}
					for (int i = 0; i < round; i ++ ) {

						res[bias_y][i + bias_y] = num ++;
					}
					bias_y ++;
				}
				round --;
			}
			return res;
		}
};
