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
public:
	vector<string> res;
	Solution() {		
	}
	void dfs (string s, int dep, int len) {
		if (s.length() == len*2) {
			res.push_back(s);
			return;
		}
		if (dep > 0) {
			dfs (s+')', dep-1, len);
		}
		if (dep < len && s.length() + dep < len*2) {
			dfs(s+'(', dep+1, len);
		}		
	}
    vector<string> generateParenthesis(int n) {
        dfs("", 0, n);
        return res;
    }
};



void test(){
	Solution t = Solution();
	auto res = t.generateParenthesis(3);
	for (auto i:res) {
		cout<<i<<endl;
	}
}

int main(){
	test();
	return 0;
}
