class Solution {

	public:
		int maxSubArray(vector<int>& nums) {

			int _sum = 0;
			int res = -2147483647;
			for (auto i: nums) {

				_sum += i;
				res = max(_sum, res);
				if (_sum < 0) {

					_sum = 0;
				}
			}
			return res;
		}
};
