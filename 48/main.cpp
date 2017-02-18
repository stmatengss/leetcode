/*************************************************************************
    > File Name: 46/main.cpp
    > Author: stmatengss
    > Mail: stmatengss@163.com 
    > Created Time: Mon Feb  6 21:32:54 2017
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = n - 1;
        int n_h = n / 2;
        int temp = 0;
        if (n & 1) {
            for (int i = 0; i < n_h; i ++ ) {
                for (int j = 0; j < n_h + 1; j ++ ) {
                    temp = matrix[i][j];
                    matrix[i][j] = matrix[m - j][i];
                    matrix[m - j][i] = matrix[m - i][m - j];
                    matrix[m - i][m - j] = matrix[j][m - i];
                    matrix[j][m - i] = temp;
                }
            }
        } else {
            for (int i = 0; i < n_h; i ++ ) {
                for (int j = 0; j < n_h; j ++ ) {
                    temp = matrix[i][j];
                    matrix[i][j] = matrix[m - j][i];
                    matrix[m - j][i] = matrix[m - i][m - j];
                    matrix[m - i][m - j] = matrix[j][m - i];
                    matrix[j][m - i] = temp;
                }
            }
        }
    }
};

void test() {
	Solution t = Solution();
    std::vector<vector<int>> v1({
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16},
    });
    std::vector<vector<int>> v2({
        { 1,  2,  3},
        { 5,  6,  7},
        { 9, 10, 11},
    });
    t.rotate(v1);	
    for (auto i: v1) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    t.rotate(v2);    
    for (auto i: v2) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
	test();
	return 0;
}