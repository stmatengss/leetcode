#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
//    	bool flag = x>=0?true:false;
    	long long res = 0;
        while (x) {
        	res *= 10;
        	res += x%10;
        	x /= 10;
		}
		return res;
    }
};

void test(){
	Solution t = Solution();
	cout<<t.reverse(123)<<endl;
	cout<<t.reverse(-123)<<endl;
	cout<<t.reverse(1073741824)<<endl;
//	cout<<(1<<31-1)<<endl;
	cout<<t.reverse(1534236469)<<endl;
}

int main(){
	test();
	return 0;
}
