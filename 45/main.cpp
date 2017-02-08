/*************************************************************************
    > File Name: 45/main.cpp
    > Author: stmatengss
    > Mail: stmatengss@163.com 
    > Created Time: Mon Feb  6 20:59:34 2017
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    int jump(vector<int> nums) {
    	vector<int> dp(nums.size(), 1<<30);
    	int max_dis = 0;
    	int now_dis = 0;
    	int res = 0;
        for (int i = 0; i < nums.size() - 1; i ++ ) {
        	if (max_dis < i) {
        		res ++;
        		max_dis = now_dis;
        	} else {
        		now_dis = max(now_dis, A[i] + i);
        	}
        	
        }
        return res;
    }
};