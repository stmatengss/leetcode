#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
private:
	map<char, string > mp;
public:
	Solution () {
		mp['0'] = " ";
		mp['1'] = " ";
		mp['2'] = "abc";
		mp['3'] = "def";
		mp['4'] = "ghi";
		mp['5'] = "jkl";
		mp['6'] = "mno";
		mp['7'] = "pqrs";
		mp['8'] = "tuv";
		mp['9'] = "wxyz";
	}
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        queue<string> q;
        vector<string> res;
        q.push("");
		while (!q.empty()) {
			string s = q.front();
			q.pop();
			if (s.length() == len) {
				res.push_back(s);
			} else {
				string ss = mp[digits[s.length()]];
				for (int i = 0; i < ss.length(); i++) {
					q.push(s + ss[i]);
				}
			}
		}
		return res;
    }
};


void test(){
	Solution a = Solution();
	auto b = a.letterCombinations("23");
	for (string i:b) {
		cout<<i<<endl;
	}
}

int main(){
	test();
	return 0;
}
