class Solution {
public:
    // string getPermutation(int n, int k) {
    //     string s(n, '1');
    //     for (int i = 0; i < n; i ++) {
    //         s[i] = '1' + i;
    //     }
    //     k --;
    //     while(next_permutation(s.begin(), s.end()) && --k);
    //     return s;
    // }
    string getPermutation(int n, int k) {
        string s(n, '1');
        string res(n, '1');
        int a = 1;
        for (int i = 1; i <= n; i ++) {
            s[i - 1] = '0' + i;
            a *= i;
        }
        k --;
        for (int i = n, j = 0; i >= 1; i --, j ++ ) {
            a /= i;
            int r = k / a;
            k %= a;
            int counter = 0;
            int l;
            for (l = 0; l < n; l ++ ) {
                if (s[l] == '0') {
                    continue;
                }
                if (counter == r) {
                    break;
                }
                counter ++;
            }
            res[j] = s[l];
            s[l] = '0';         
        }
        return res;
    }
};
