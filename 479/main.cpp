/*************************************************************************
    > File Name: 46/main.cpp
    > Author: stmatengss
    > Mail: stmatengss@163.com 
    > Created Time: Mon Feb  6 21:32:54 2017
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

// 9 9
// 6006 658
// 698896 982
// 28233282 1190
// 2704884072 709
// 637832238736 1127
// 27237788773272 350
// 4099923883299904 765

using namespace std;

class Solution {
public:
    typedef long long ll;

    const int a[10] = {9, 987, 123, 597, 677, 1218, 877, 475};
    inline bool isPa(ll num) {
        string s = "";
        while(num) {
            s += num % 10;
            num /= 10;
        }
        string ss = s;
        reverse(s.begin(), s.end());
        return ss == s;
    }
    void makeSolution() {
        ll begin = 10;
        for (int i = 1; i <= 5; i ++, begin *= 10 ) {
            ll max_num = -1;
            ll j = begin - 1;
            ll k = begin - 1;

            ll delta = ll(begin / 40);

            for (j = begin - 1; j > begin - 1 - delta; j -- ) {
                for (k = begin - 1; k > begin - 1 - delta; k -- ) {
                    ll num = j * k;
                    if (isPa(num)) {
                        max_num = max(max_num, num);
                    } 
                }
            }

            // while (j) {
            //     ll num1 = (j - 1) * (k);
            //     ll num2 = (j) * (k - 1);
            //     if (num1 > num2) {
            //         if (isPa(num1)) {
            //             max_num = max(max_num, num1);
            //         }  
            //         j--;
            //     } else {
            //         if (isPa(num2)) {
            //             max_num = max(max_num, num2);
            //         }  
            //         k--;
            //     }
            // }
            cout << max_num << " " << max_num % 1337 <<endl;
        }
    }
    int largestPalindrome(int n) {
        return a[n-1];
    }
};

void test() {
	Solution t = Solution();
    t.makeSolution();
    cout << t.largestPalindrome(1) <<endl;
}

int main() {
	test();
	return 0;
}