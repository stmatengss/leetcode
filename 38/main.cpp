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
	Solution() {

	}
    string countAndSay(int n) {
    	vector<char> res[2];
    	res[0].push_back('1');
    	for(int i = 0; i < n; i ++ ) {
    		int counter = 1; 
    		res[i % 2].push_back('f');
    		res[(i + 1) % 2].clear();
    		for(int j = 0; j < res[i % 2].size() - 1; j ++) {
    			if (res[i % 2][j] != res[i % 2][j + 1]) {
    				res[(i + 1) % 2].push_back('0' + counter);
    				res[(i + 1) % 2].push_back(res[i % 2][j]);
    				counter = 0;
    			}
    			counter ++;
    		}
    	}   
    	return string(res[n % 2].begin(), res[n % 2].end());
    }
};

void test() {
	Solution t = Solution();
	cout << t.countAndSay(0) << endl;
	cout << t.countAndSay(1) << endl;
	cout << t.countAndSay(2) << endl;
	cout << t.countAndSay(3) << endl;
	cout << t.countAndSay(4) << endl;
	cout << t.countAndSay(5) << endl;
}

int main () {
	test();
	return 0;
}

