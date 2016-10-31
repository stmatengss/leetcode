#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int len = nums.size();
    	int res = 1<<30;
    	int ret = 0;
    	auto myabs = [](int x){
    		return x>0?x:-x;
		};
    	sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
        	if (i == 0 || nums[i-1] != nums[i]) {
	        	int pr = len - 1;
	    		int pl = i + 1;
	    		
	    		while (pr > pl) {
	    			int sum = nums[i] + nums[pl] + nums[pr];
	    			if(res > myabs(sum-target)) {
	    				ret = sum;
	    				res = myabs(sum-target);
					}
	    			if (sum == target) {
	    				return target;
						pr--;
						pl++;
	    				
					} else if (sum > target) {
						pr--;
					} else {
						pl++;
					}
				}    
			}
			  	
		}
		return ret;
    }
};


void test(){
	vector<int>tmp;
	tmp.push_back(-1);
	tmp.push_back(-2);
	tmp.push_back(1);
	tmp.push_back(4);
//	tmp.push_back(2);
//	tmp.push_back(-4);
	Solution a = Solution();
	auto b = a.threeSumClosest(tmp, 1);
	cout<<b<<endl;
}

int main(){
	test();
	return 0;
}
