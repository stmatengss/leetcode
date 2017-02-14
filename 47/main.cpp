/*************************************************************************
    > File Name: 46/main.cpp
    > Author: stmatengss
    > Mail: stmatengss@163.com 
    > Created Time: Mon Feb  6 21:32:54 2017
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)  {
    	vector<vector<int>> res;
    	sort(nums.begin(), nums.end());
        do {
        	res.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        return res;
    }
};

void test() {
	Solution t = Solution();
    vector<int> data({0, 0, 1});
	for(auto i: t.permuteUnique(data) ) {
		for(auto j: i) {
			cout << j << " ";
		}
		cout << endl;
	}
}

int main() {
	test();
	return 0;
}