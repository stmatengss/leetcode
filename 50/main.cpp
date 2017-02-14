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

using namespace std;

class Solution {
public:
    typedef unsigned int uint;
    typedef long long ll;
    double myPow(double x, int n) {
        if (x == 1.000) {
            return 1.0;
        }
        if (x == 0.000) {
            return 0.0;
        }
        double res = 1.0;
        ll m;
        if (n > 0) {
            m = (ll)n;
        } else {
            m = -(ll)n;
            x = 1.0 / x;
        }
        while(m) {
            if (m & 1) {
                res *= x;
            }
            x = x * x;
            m >>= 1;
        }
        return res;
    }
};

void test() {
	Solution t = Solution();
    cout << t.myPow(3, 2) << endl;
    cout << t.myPow(4, 4) << endl;
    cout << t.myPow(2, 0) << endl;
    cout << t.myPow(2, -2) << endl;
    cout << t.myPow(2, -2147483648) << endl;
}

int main() {
	test();
	return 0;
}