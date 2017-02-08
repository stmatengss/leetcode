/*************************************************************************
    > File Name: 41/main.cpp
    > Author: stmatengss
    > Mail: stmatengss@163.com 
    > Created Time: Mon Feb  6 17:05:54 2017
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> nums) {
		int len = nums.size();
		for (auto &i: nums) {
			if (i <= 0) {
				i = len + 2;
			}
		}
		// for_each(nums.begin(), nums.end(), [](int i) {
		// 	cout << i <<endl;
		// });
		for (auto i: nums) {
			int index = i > 0 ? i : -i;
			if (index <= len) {
				if (nums[index - 1] > 0) {
					nums[index - 1] = - nums[index - 1];
				}
			}
		}
		// for_each(nums.begin(), nums.end(), [](int i) {
		// 	cout << i <<endl;
		// });
		for (int i = 0; i < nums.size(); i ++ ) {
			if (nums[i] > 0) return i + 1;
		} 
		return len + 1;
    }
};


void test() {
	vector<int> a({3, 4, -1, 1});
	Solution t = Solution();
	cout << t.firstMissingPositive(a) << endl; 
}

int main() {
	test();
	return 0;
}