#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		s = "#" + s +"$";
		string rs = s;
		reverse(s.begin(), s.end());
		cout<<s<<endl;
		cout<<rs<<endl;
		int i,j,k;
		int counter1, counter2, max_len = -1, len;
		string res = "";
		bool flag1, flag2;
		for (i=0; i<s.length(); i++) {
				counter1 = 0;
				counter2 = 0;
				flag1 = true;
				flag2 = true; 
				for (j=i, k=0; j<s.length(); j++, k++) {
					if (s[j] == rs[k]) {
						flag1 = false;
						counter1 ++;
					} else {
						if (flag1 == false) {
							flag1 = true;
							if (counter1 > max_len && j-counter1 == (s.length()-k)) {
								max_len = counter1;
								cout<<"casea "<<j<<" "<<k<<endl;
								res = s.substr(j-counter1, counter1);
								cout<<res<<endl;
							}
						}
						counter1 = 0;
					}
					if (rs[j] == s[k]) {
						flag2 = false;
						counter2 ++;
					} else {
						if (flag2 == false) {
							flag2 = true;
							if (counter2 > max_len && j-counter2 == (s.length()-k)) {
								max_len = counter2;
								cout<<"caseb "<<j<<" "<<k<<endl;
								res = rs.substr(j-counter2, counter2);
								cout<<res<<endl;
							}
						}
						counter2 = 0;
					}
				}
		}
		return res;
	}
};

void test(){
	Solution a = Solution();
	//cout<<a.longestPalindrome("aba")<<endl;
	//cout<<a.longestPalindrome("csdfsaaabaa")<<endl;
	//cout<<a.longestPalindrome("abba")<<endl;
	//cout<<a.longestPalindrome("")<<endl;
	cout<<a.longestPalindrome("aveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheeart")<<endl;
	cout<<a.longestPalindrome("a")<<endl;
	cout<<a.longestPalindrome("pleforthep")<<endl;
	cout<<a.longestPalindrome("notperishfromtheea")<<endl;
}

int main(){
	test();
	return 0;
}
