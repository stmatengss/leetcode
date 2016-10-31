#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

typedef vector<int> vec;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
//        int len = nums.size();
		int len = nums.length();	
		next_permutation(nums.begin(), nums.end());
 		for(int i = len-1; i >= 0; i--) {

 		}
		
    }
};

template<typename T>
void print(T &a) {
	for(auto i:a) {
		cout<<i<<endl;	
	}
}

void test() {
	int a[] = {1, 1, 5};
	vec aa(a, a+3);
	Solution t = Solution();
	t.nextPermutation(aa);
	print(aa);
	}

int main(){
	test();
	return 0;
}
