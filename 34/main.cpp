/*************************************************************************
  > File Name: 34/main.cpp
  > Author: stmatengss
  > Mail: stmatengss@163.com 
  > Created Time: Wed Feb  1 12:31:01 2017
 ************************************************************************/


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

class Solution {

	public:
		vector<int> searchRange(vector<int>& nums, int target) {
			vector<int> res(2, -1);
			if(!nums.size()) {
				return res;
			}
			auto begin = lower_bound(nums.begin(), nums.end(), target);
			auto end = upper_bound(begin, nums.end(), target);
			//if(begin == nums.end() || end == nums.end() || *begin != target || *(end - 1) != target) {
			if((begin != nums.end() && *begin != target) || *(end - 1) != target) {
				return res;
			}
			res[0] = begin - nums.begin();
			res[1] = end - nums.begin() - 1;
			return res;
		}
};

void test() {
	Solution *t = new Solution();
	vector<int> a({
		5, 7, 7, 8, 8, 10
	});
	vector<int> b({
		0, -1
	});
	vector<int> c({
		1,1	
	});
	vector<int> d({
		0, 1, 3, 4
	});

	auto res = t->searchRange(a, 8);
	auto res2 = t->searchRange(b, 3);
	auto res3 = t->searchRange(c, 2);
	auto res4 = t->searchRange(d, 2);
	for(auto i: res) {
		cout << i << endl;
	}
	for(auto i: res2) {
		cout << i << endl;
	}
	for(auto i: res3) {
		cout << i << endl;
	}
	for(auto i: res4) {
		cout << i << endl;
	}
}

int main() {
	test();
	return 0;
}

