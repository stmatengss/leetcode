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
    int strStr(string haystack, string needle) {
    	auto pos = haystack.find(needle);
        if (pos == string::npos) return -1;
		return pos;
    }
};

int main(){
	test();
	return 0;
}
