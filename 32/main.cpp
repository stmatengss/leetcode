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

typedef vector<int> vec;

class Solution {
public:
//	int a[100004];
    int longestValidParentheses(string s) {
		const int len = s.length();
		if(len == 0) return 0;
		int maxn = 0;
		vector<int> a(len);
//		int* a = (int* )malloc(sizeof(int) * (len+2));
		a[0] = 0;
		for(int i = 1; i < len; i++) {
			if(s[i] == '(') {
				a[i] = 0;
			} else {
				if((i-a[i-1]-1) >=0 && s[i-a[i-1]-1] == '(') {
					a[i] = a[i-1] + 2;
					if((i-a[i-1]-2) >= 0) {
						a[i] += a[i-a[i-1]-2];	
					}
				}
			}
//			cout<<a[i]<<endl;
			maxn = max(maxn, a[i]);
		}
		return maxn;
    }
};

//    int longestValidParentheses(string s) {
//        int maxn = 0;
//        int st = 0;
//        int len = 0;
//		for(auto i:s) {
//        	if(i == '(') {
//        		if(st) {
//        			st++;
//				} 
//			} else {
//				if(st) {
//					st--;
//				} else {
//					len = 0;
//				}
//			}
//			if(st == 0) maxn = max(maxn, len);
//		}
//		return maxn;
//    }

void test() {
	auto t = Solution();
	cout<<t.longestValidParentheses("()()))))()()(")<<endl;
	cout<<t.longestValidParentheses("))))((()((")<<endl;
}

int main(){
	test();
	return 0;
}
