#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<list>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    	int len = s.length();
    	if (numRows == 1) return s;
    	int block = (2*numRows-2);
    	int numCols = len/block+1;
    	string res = "";
    	int pos;
        //vector<vector<char> > v(numRows, vector<char>(len/numRows+1);
		int i, j;
		for(i=0;i<numRows;i++) {
			for(j=0;j<numCols;j++) {
				pos = block*(j)+i;
				
				if (pos<len) {
//						cout<<"a"<<pos<<s[pos]<<endl;
						res += s[pos];
				}
				if(i!=0 && i!=numRows-1) {
					pos = block*(j+1)-i;
					if (pos<len) {
//						cout<<"b"<<pos<<s[pos]<<endl;
						res += s[pos];
					}
				}				
			}
		}
		return res;
    }
};

void test()
{
	Solution a = Solution();
	cout<<(a.convert("PAYPALISHIRING",3))<<endl;
	cout<<(a.convert("",1))<<endl;
}

int main()
{
	test();
	return 0;
}
