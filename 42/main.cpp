/*************************************************************************
    > File Name: 42/main.cpp
    > Author: stmatengss
    > Mail: stmatengss@163.com 
    > Created Time: Mon Feb  6 20:29:07 2017
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
    
using namespace std;

class Solution {
public:
    int trap(vector<int> height) {
    	const int len = height.size();
    	vector<int> left(len);
    	// vector<int> right(len);
    	int le_max = -1;
    	int ri_max = -1;
        for (int i = 0; i < len; i ++ ) {
        	if (height[i] > le_max) {
        		le_max = height[i];
        	} 
        	left[i] = le_max;
        }
        int sum = 0;
        for (int i = len - 1; i >= 0; i -- ) {
        	if (height[i] > ri_max) {
        		ri_max = height[i];
        	} 
        	sum += min(left[i], ri_max) - height[i];
        }
        
        return sum;
    }
    int trap2(vector<int> height) {
    	const int len = height.size();
    	vector<int> left(len);
    	vector<int> right(len);
    	int le_max = -1;
    	int ri_max = -1;
        for (int i = 0; i < len; i ++ ) {
        	if (height[i] > le_max) {
        		le_max = height[i];
        	} 
        	left[i] = le_max;
        }
        for (int i = len - 1; i >= 0; i -- ) {
        	if (height[i] > ri_max) {
        		ri_max = height[i];
        	} 
        	right[i] = ri_max;
        }
        int sum = 0;
        for (int i = 0; i < len; i ++ ) {
        	sum += min(left[i], right[i]) - height[i];
        }
        return sum;
    }
};

void test() {
	vector<int> a({0,1,0,2,1,0,1,3,2,1,2,1});
	Solution t = Solution();
	cout << t.trap(a) << endl;
}

int main() {
	test();
	return 0;
}