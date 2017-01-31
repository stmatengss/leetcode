/*************************************************************************
  > File Name: 35/main.cpp
  > Author: stmatengss
  > Mail: stmatengss@163.com 
  > Created Time: Tue Jan 31 11:36:56 2017
 ************************************************************************/

class Solution {

	public:
		int searchInsert(vector<int>& nums, int target) {

			vector<int>::iterator pos;
			pos = lower_bound(nums.begin(), nums.end(), target);
			return (pos - nums.begin());
		}
};
