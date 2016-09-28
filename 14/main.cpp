#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	int len = nums.size();
    	vector<vector<int>> res;
    	int a = 1<<30, b = 1<<30, c = 1<<30;
    	sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
        	if (i == 0 || nums[i-1] != nums[i]) {
	        	int pr = len - 1;
	    		int pl = i + 1;
	    		
	    		while (pr > pl) {
	    			int sum = nums[i] + nums[pl] + nums[pr];
	    			if (sum == 0) {
	    				if (a != nums[i] || b != nums[pl] || c != nums[pr]) {
		    				vector<int> out;
		    				out.push_back(nums[i]);
		    				out.push_back(nums[pl]);
		    				out.push_back(nums[pr]);
							res.push_back(out);
							a = nums[i];
							b = nums[pl];
							c = nums[pr];
						}
						pr--;
						pl++;
	    				
					} else if (sum > 0) {
						pr--;
					} else {
						pl++;
					}
				}    
			}
			  	
		}
		return res;
    }
};


void test(){
	vector<int>tmp;
	tmp.push_back(-2);
	tmp.push_back(0);
	tmp.push_back(1);
	tmp.push_back(1);
	tmp.push_back(2);
//	tmp.push_back(-4);
	Solution a = Solution();
	auto b = a.threeSum(tmp);
	for (int i = 0; i < b.size(); i++) {
		cout << b[i][0] << ' ' << b[i][1] << ' ' << b[i][2] <<endl;
	}
}

int main(){
	test();
	return 0;
}
