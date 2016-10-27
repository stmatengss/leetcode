#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int len = nums.size();
    	if (len == 0) return 0;
    	int res = 1;
    	int p = 0;
        for (int i = 1; i < len; i++) {
        	if (nums[i] != nums[i-1]) {
        		nums[res] = nums[i];
				res++;			
			} 
		}
		nums.resize(res);
		return res;
    }
};

void test(){

}

int main(){
	test();
	return 0;
}
