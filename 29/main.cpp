#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<queue>
#include<limits>

using namespace std;


class Solution {
public:
	typedef long long ll;
	inline ll myabs(int a) {
		ll b = (ll)a;
		return b<0?-b:b;
	}
    int divide(int dividend, int divisor) {
    	if (divisor == 0) 
			return numeric_limits<int>::max();
        ll res = 0;
        int num = 1;
        int flag = \
			(dividend>0 && divisor>0 || dividend<0 && divisor<0)?1:0;
		ll x = myabs(dividend), y = myabs(divisor);
		while (x > y) {
        	y <<= 1;
        	num++;
		}
		while(num--) { 
			res <<= 1;
			if (x - y >= 0) {
				x -= y;
				res += 1;
			}
			y >>= 1;
		}
		res = flag?res:-res;
		if(res > numeric_limits<int>::max())
			return numeric_limits<int>::max();
		return res;
    }
};

void test() {
	Solution t = Solution();
	cout<<t.divide(-2147483648,-1)<<endl;
		cout<<t.divide(8,2)<<endl;
			cout<<t.divide(6,3)<<endl;
				cout<<t.divide(9,1)<<endl;
	cout<<t.divide(-9,-1)<<endl;
	cout<<t.divide(-9,1)<<endl;
	cout<<t.divide(0,1)<<endl;
	cout<<t.divide(2,3)<<endl;
	cout<<t.divide(2,0)<<endl;
	cout<<t.divide(2147483647,1)<<endl;
}

int main(){
	test();
	return 0;
}
