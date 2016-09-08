#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	inline int trans(char a) {
		return a - 'a';
	}
    int lengthOfLongestSubstring(string s) {
        int hashtable[270] = {0};
        int max_length = 0;
        int max_i, max_j;
        int i = 0, j = 0;
        for (;i < s.size();i++) {
        	if (hashtable[s[i]] == 1) {
        	   	while (j <= i) {	
        			hashtable[s[j]]--;
        			j++;
        			if (s[j-1] == s[i]) {
        				break;
					}
				}	
			}
			hashtable[s[i]]++;
			if ( (i-j+1) > max_length ) {
				max_length = (i-j+1);
				max_i = i;
				max_j = j;
			}
		}
		return max_length;
    }
};

void test()
{
	Solution a = Solution();
	cout<<a.lengthOfLongestSubstring("abcabcbb")<<endl;
		cout<<a.lengthOfLongestSubstring("bbbbb")<<endl;
			cout<<a.lengthOfLongestSubstring("pwwkew")<<endl;
}

int main()
{
	test();
	return 0;
}
