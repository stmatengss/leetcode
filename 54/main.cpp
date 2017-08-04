#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {

	public:
		// vector<int> spiralOrder(vector<vector<int>>& matrix) {

		// 	int m = matrix.size();
		// 	int n = matrix[0].size();
		// 	vector<int> res;

		// 	int begin_x = 0, begin_y = 0, end_x = m - 1, end_y = n - 1;

		// 	for (int i = 0; i < min(m, n); i ++ ) {

		// 		for (int j = begin_y; j <= end_y; j ++ ) {

		// 			res.push_back(matrix[begin_x][j]);
		// 			cout << (matrix[begin_x][j]) << endl;
		// 		}
		// 		begin_x ++;
		// 		for (int j = begin_x; j <= end_x; j ++ ) {

		// 			res.push_back(matrix[j][end_y]);
		// 			cout << matrix[j][end_y] << endl;
		// 		}
		// 		end_y --;
		// 		for (int j = end_y; j >= begin_y; j -- ) {

		// 			res.push_back(matrix[end_x][j]);
		// 			cout << matrix[end_x][j] << endl;
		// 		}
		// 		end_x --;
		// 		for (int j = end_x; j >= begin_x; j -- ) {

		// 			res.push_back(matrix[j][begin_y]);
		// 			cout << matrix[j][begin_y] << endl;
		// 		}
		// 		begin_y ++;
		// 	}
		// 	return res;
		// }
		vector<int> spiralOrder(vector<vector<int>>& matrix) {

			int m = matrix.size();
			int n = matrix[0].size();
			vector<int> res;

			int begin_x = 0, begin_y = 0, end_x = m - 1, end_y = n - 1;
			int status = 0;

			int x = 0, y = 0;
			int counter = 0;
			int sum = m * n;

			for (int i = 0; i < min(m, n); i ++ )  {

				for (int j = begin_y; j <= end_y; j ++ ) {
					if (counter++ >= sum)break;
					res.push_back(matrix[begin_x][j]);
				}
				
				begin_x ++;
				for (int j = begin_x; j <= end_x; j ++ ) {
					if (counter++ >= sum)break;
					res.push_back(matrix[j][end_y]);
				}
				end_y --;
				for (int j = end_y; j >= begin_y; j -- ) {
					if (counter++ >= sum)break;
					res.push_back(matrix[end_x][j]);
				}
				end_x --;
				for (int j = end_x; j >= begin_x; j -- ) {
					if (counter++ >= sum)break;
					res.push_back(matrix[j][begin_y]);	
				}
				begin_y ++;
			}
			return res;
		}
};

int main() {
	Solution *t = new Solution();
	// vector<vector<int> > test{
	// 	{1},
	// 	{1},{1},{1},{1},
	// };
		vector<vector<int> > test{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
		{7, 8, 9},
		{7, 8, 9},
		{7, 8, 9}
	};
	auto res = t->spiralOrder(test);
	for (auto i: res) {
		cout << i << endl;
	}
	return 0;
}
