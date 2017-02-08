/*************************************************************************
  > File Name: 36/main.cpp
  > Author: stmatengss
  > Mail: stmatengss@163.com 
  > Created Time: Wed Feb  1 14:18:07 2017
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;


class Solution {

	private:
		inline int trans(char x) {

			return (int)(x - '1'); 
		}
	public:
		bool isValidSudoku(vector<vector<char>>& board) {

			for(int x = 0; x < 9; x += 3 ) {

				for(int y = 0; y < 9; y += 3 ) {

					vector<int> flag(9, 0);
					for(int i = 0; i <= 2; i ++ ) {

						for(int j = 0; j <= 2; j ++ ) {

							if(board[x + i][y + j] == '.')continue;
							int num = trans(board[x + i][y + j]);
							if(flag[num] == 1) {

								return false;
							}
							flag[num] ++;
						}
					}
				}
			}
			for(int i = 0; i < 9; i ++ ) {

				vector<int> flag1(9, 0);
				for(int j = 0; j < 9; j ++ ) {

					if(board[i][j] == '.')continue;
					int num1 = trans(board[i][j]);
					if(flag1[num1] == 1) {

						return false;
					}
					flag1[num1] ++;
				}
			}
			for(int i = 0; i < 9; i ++ ) {

				vector<int> flag2(9, 0);
				for(int j = 0; j < 9; j ++ ) {

					if(board[j][i] == '.')continue;
					int num2 = trans(board[j][i]);
					if(flag2[num2] == 1) {

						return false;
					}
					flag2[num2] ++;
				}
			}
			return true;
		}
};
void test() {

	Solution *t = new Solution();

}

int main() {

	return 0;
}
