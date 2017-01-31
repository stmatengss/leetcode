/*************************************************************************
  > File Name: main.cpp
  > Author: stmatengss
  > Mail: stmatengss@163.com 
  > Created Time: Tue Jan 31 11:29:01 2017
 ************************************************************************/

class Solution {

	public:
		int search(vector<int>& nums, int target) {

			if (!nums.size()) return -1;
			int left = 0, right = nums.size() - 1;
			int middle;
			while(left <= right) {

				middle = (left + right) / 2;
				if(nums[middle] == target) return middle;


				if(nums[right] < nums[middle]) {

					if(target >= nums[left] && target <= nums[middle])right = middle - 1;
					else left = middle + 1;
				} else {

					if(target >= nums[middle] && target <= nums[right])left = middle + 1;
					else right = middle - 1;
				}
			}
			return -1;
		}
};
