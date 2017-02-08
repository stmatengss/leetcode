#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool isMatch(string s, string p) {
        if (p.size() == 0) {
        	return s.size() == 0;
        }
        if (p.size() >= 2 && p[1] == '*') {
        	int i;
	        for(i = 0; i < s.size(); i ++ ) {
	        	if (!((p[0] == '.') || (s[i] == p[0]) ) ) break;
	        	if (isMatch(s.substr(i, s.size() - i), p.substr(2, p.size() - 2))) return true;
	        }
	    	return isMatch(s.substr(i, s.size() - i), p.substr(2, p.size() - 2));
		} else if (((s.size() != 0 && p[0] == '.') || (s[0] == p[0]) )) {
			return isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
		}
		return false;
    }

};

void test(){
	Solution t = Solution();
	cout << t.isMatch("aa","a") << endl; 
	cout << t.isMatch("aa","aa") << endl; 
	cout << t.isMatch("aaa","aa") << endl; 
	cout << t.isMatch("aa", "a*") << endl; 
	cout << t.isMatch("aa", ".*") << endl; 
	cout << t.isMatch("ab", ".*") << endl; 
	cout << t.isMatch("aab", "c*a*b") << endl; 
}

int main(){
	test();
	return 0;
}
