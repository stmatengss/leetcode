#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
		typedef long long ll;
	inline bool illegal(ll x) {
		if (x >= lb)
			return true;
		if (-1*x >= lb)
			return true;
		return false;
	}
	
    int reverse(int x) {
//    	bool flag = x>=0?true:false;
		if (illegal((ll)x))
			return 0;
    	ll res = 0;
        while (x) {
        	res *= 10;
        	//cout<<(x%10)<<endl;
        	res += x%10;
        	x /= 10;
		}
		if(illegal(res))
			return 0;
		return res;
    }
private:
	const long long lb = 1LL<<31;
};

void test(){
	Solution t = Solution();
//	cout<<t.reverse(123)<<endl;
//	cout<<t.reverse(-123)<<endl;
//	cout<<t.reverse(-5612312)<<endl;
	cout<<t.reverse(1073741824)<<endl;
	cout<<t.reverse(-2143847412)<<endl;
	cout<<t.reverse(-2147483648)<<endl;
//	cout<<(1<<31-1)<<endl;
	cout<<t.reverse(1463847412)<<endl;
	cout<<t.reverse(1534236469)<<endl;
}

int main(){
	test();
	return 0;
}
