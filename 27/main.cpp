#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
    	if (len == 0) return 0;
    	int res = 0;
        for (int i = 0; i < len; i++) {
        	if (nums[i] != val) {
        		nums[res] = nums[i];
				res++;			
			} 
		}
		nums.resize(res);
		return res;
    }
};

int main(){
	test();
	return 0;
}
