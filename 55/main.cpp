class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int maxn = 0;
        for (int i = 0; i < len; i ++ ) {
            if (maxn < i) return false;
            maxn = max(i + nums[i], maxn);
        }
        return true;
    }
};