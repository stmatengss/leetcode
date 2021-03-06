#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
private:
	char pre[4] = {'(', '{', '['};
	map<char, char> mp;
	bool ispre(char c){
		for (int i = 0; i < 3; i++) {
			if (c == pre[i]) {
				return true;
			}
		}
		return false;
	}
public:
	Solution() {
		mp[')'] = '(';
		mp['}'] = '{';
		mp[']'] = '[';
	}
    bool isValid(string s) {
    	stack<char> st;
		for (char i:s) {
    		if (ispre(i)) {
    			st.push(i);
			} else {
				if (st.empty()) {
					return false;
				}
				char p = st.top();
				st.pop();
				if (mp[i] != p) {
					return false;
				}
			}
		}	    
		if (st.empty()) {
			return true;
		}			
		return false;
    }
};

void test(){
	Solution t = Solution();
	cout<<t.isValid("()[]{")<<endl;
}

int main(){
	test();
	return 0;
}
