#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	const char *s, *p;
	int len_s, len_p;

	bool isMatch(string ss, string pp) {
		s = (ss + '\0').c_str();
		len_s = ss.length();
		p = (pp + '\0').c_str();
		len_p = pp.length();
		return isMatch2(0, 0);
	}

    bool isMatch2(int pos_s, int pos_p) {
        if (p[pos_p] == '\0') {
        	return s[pos_s] == '\0';
        }
        if (p[pos_p + 1] == '*') {
        	int i;
	        for(i = pos_s; i < len_s; i ++ ) {
	        	if (!((p[pos_p] == '.') || (s[i] == p[pos_p]) ) ) break;
	        	if (isMatch2(i, pos_p + 2)) return true;
	        }
	    	return isMatch2(i, pos_p + 2);
		} else if ((p[pos_p] == '.' || (s[pos_s] == p[pos_p]) )) {
			return isMatch2(pos_s + 1, pos_p + 1);
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
