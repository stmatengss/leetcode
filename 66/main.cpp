class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool st = true;
        for (int i = digits.size() - 1; i >= 0; i -- ) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] = digits[i] + 1;
                st = false;
                break;
            }
        }
        if (st) {
            vector<int> res(1, 1);
            res.insert(res.end(), digits.begin(), digits.end());
            return res;
        } else {
            return digits;
        }
    }
};
