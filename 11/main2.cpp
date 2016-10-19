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
	int mp[256];
public:
	Solution() {
		mp[')'] = 3;
		mp['}'] = 4;
		mp[']'] = 5;
		mp['('] = 0;
		mp['{'] = 1;
		mp['['] = 2;
	}
    bool isValid(string s) {
    	stack<int> st;
		for (char i:s) {
			int flag = mp[i];
    		if (flag < 3) {
    			st.push(flag);
			} else {
				if (st.empty()) {
					return false;
				}
				int p = st.top();
				st.pop();
				if (flag != p+3) {
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
	cout<<t.isValid("()[]{}")<<endl;
}

int main(){
	test();
	return 0;
}
