#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
		int len = nums.size();
		int pre[4];
        if (len <= 3) {
        	return res;
		}
		for (int i = 0; i <= 3; i++) {
			pre[i] = 0xffff;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len-3; i++) {
			if (i ==0 || nums[i] != nums[i-1]) {
				for (int j = i + 1; j < len-2; j++) {
	        		if (j == i + 1 || nums[j] != nums[j-1]) {
	        			int pr = len - 1;
		    			int pl = j + 1;
		        		while (pr > pl) {
			    			int sum = nums[i] + nums[j] + nums[pl] + nums[pr];
			    			if (sum == target) {
			    				if (pre[0] != nums[i] || pre[1] != nums[j] || pre[2] != nums[pl] || pre[3] != nums[pr]) {
				    				vector<int> out;
				    				out.push_back(nums[i]);
				    				out.push_back(nums[j]);
				    				out.push_back(nums[pl]);
				    				out.push_back(nums[pr]);
									res.push_back(out);
									pre[0] = nums[i];
									pre[1] = nums[j];
									pre[2] = nums[pl];
									pre[3] = nums[pr];
								}
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
			}      	
		}
		return res;
    }
};


void test(){
	vector<int>tmp;
	tmp.push_back(2);
	tmp.push_back(0);
	tmp.push_back(3);
	tmp.push_back(0);
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(4);
	Solution a = Solution();
	auto b = a.fourSum(tmp, 7);
	for (int i = 0; i < b.size(); i++) {
		cout << b[i][0] << ' ' << b[i][1] << ' ' << b[i][2] <<  ' ' << b[i][3] << endl;
	}
}

int main(){
	test();
	return 0;
}
