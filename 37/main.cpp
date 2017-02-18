/*************************************************************************
    > File Name: 38/main.cpp
    > Author: stmatengss
    > Mail: stmatengss@163.com 
    > Created Time: Mon Feb  6 14:53:21 2017
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // bool col[10];
    const int SUM = 45;
    bool check2 (vector<vector<char>>& board, int x, int y) {
        bool flag[10];
        if (x == 8) {
            fill(flag, flag + 9, false);
            for (int i = 0; i < 9; i ++ ) {
                if (flag[board[x][i] - '0'] == true) {
                    return false;
                }
                flag[board[x][i] - '0'] = true;
            }
        }
        if (y == 8) {
            fill(flag, flag + 9, false);
            for (int i = 0; i < 9; i ++ ) {
                if (flag[board[i][y] - '0'] == true) {
                    return false;
                }
                flag[board[i][y] - '0'] = true;
            }
        }
        if (x % 3 == 2 && y % 3 == 2) {
            fill(flag, flag + 9, false);
            for (int i = x - 2; i <= x; i ++ ) {
                for (int j = y - 2; j <= y; j ++ ) {
                    if (flag[board[i][j] - '0'] == true) {
                        return false;
                    }
                    flag[board[i][j] - '0'] = true;
                }       
            }
        }
        return true;
    }
    bool check (vector<vector<char>>& board, int x, int y) {
        char target = board[x][y];
        for (int i = 0; i < 9; i ++ ) {
            if (i != x && board[i][y] == target) {
                return false;
            }
        }
        for (int i = 0; i < 9; i ++ ) {
            if (i != y && board[x][i] == target) {
                return false;
            }
        }
        for (int i = x / 3 * 3; i < x / 3 * 3 + 3; i ++ ) {
            for (int j = y / 3 * 3; j < y / 3 * 3 + 3; j ++ ) {
                if ((i != x || j != y) && board[i][j] == target) {
                    return false;
                }
            }       
        }
        return true;
    }
    bool solve(int pos, vector<vector<char>>& board) {
        if (pos == 81) {
            return true;
        }
        int x = pos / 9;
        int y = pos % 9;
        // if (pos % 9 == 0) {
        //     fill(col, col + 10, true);
        //     for (int i = 0; i < 9; i ++) {
        //         if (board[x][i] != '.') {
        //             col[board[x][i] - '0'] = false;
        //         }
        //     }
        // }
        if (board[x][y] == '.') {
            for (int i = 1; i <= 9; i ++ ) {
                // if (col[i] == true) {
                //     col[i] = false;
                board[x][y] = '0' + i;
                if (check(board, x, y) && solve(pos + 1, board)) {
                    return true;
                }
                board[x][y] = '.';
                //     col[i] = true;
                // }
            }
        } else {
            return solve(pos + 1, board);
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0, board);
    }
};

void test() {
	Solution t = Solution();
    vector<vector<char>> mp({{'.', '.', '9', '7', '4', '8', '.', '.', '.'},
                             {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '2', '.', '1', '.', '9', '.', '.', '.'},
                             {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
                             {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
                             {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
                             {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
                             {'.', '.', '.', '2', '7', '5', '9', '.', '.'}});
    t.solveSudoku(mp);
    for (auto i: mp) {
        for (auto j: i) {
            cout << j;
        }
        cout << endl;
    }
}

int main () {
	test();
	return 0;
}

