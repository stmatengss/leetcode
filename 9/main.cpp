#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0) return false;
		int y = 0, t = x;
		while(t) {
			y *= 10;
			y += t%10;
			t /= 10;
		}	
		if (y==x) return true;
		return false;
	}
};

void test(){
	Solution a = Solution();
	cout<<a.isPalindrome(123)<<endl;
	cout<<a.isPalindrome(121)<<endl;
	cout<<a.isPalindrome(22)<<endl;
}

int main(){
	test();
	return 0;
}
