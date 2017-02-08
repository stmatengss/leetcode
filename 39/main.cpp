/*************************************************************************
    > File Name: 39/main.cpp
    > Author: stmatengss
    > Mail: stmatengss@163.com 
    > Created Time: Mon Feb  6 15:22:56 2017
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <array>


using namespace std;

class Solution {
public:
	vector<int> a;
	vector<vector<int>> res;
	vector<int> b;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        a = vector<int>(candidates.begin(), candidates.end());
        b = vector<int>(1000, 0);
        dfs(target, 0, 0);
        return res;
    }
    void dfs(int target, int pos, int len) {
    	if (target == 0) {
    		// cout << len << endl;
    		res.push_back(vector<int>(b.begin(), b.begin() + len));
    		return;
    	}
    	// if (target < 0) return;
    	for(int i = pos; i < a.size(); i ++ ) {
    		int counter = 0;

    		for(int j = 1; ; j ++ ) {
    			counter += a[i];
    			// cout << "j:" << j <<endl;
    			if (target - counter < 0) break;
	    		b[len + j - 1] = a[i];
	    		dfs(target - counter, i + 1, len + j);
    		}
    	}
    }
    // void dfs(int target, int pos, int len) {
    // 	// if (target < 0) return;
    // 	for(int i = pos; i < a.size(); i ++ ) {
    // 		int counter = 0;

    // 		for(int j = 1; ; j ++ ) {
    // 			counter += a[i];
    // 			// cout << "j:" << j <<endl;
    // 			if (target - counter < 0) break;
	   //  		b[len + j - 1] = a[i];
	   //  		if (target - counter == 0) {
    // 			    res.push_back(vector<int>(b.begin(), b.begin() + len + j));
    // 		        break;
    // 			}
	   //  		dfs(target - counter, i + 1, len + j);
    // 		}
    // 	}
    // }
};

void test() {
	vector<int> a({2, 3, 6, 7});
	Solution t = Solution();
	for (auto i: t.combinationSum(a, 7)) {
		for (auto j: i) {
			cout << j << " " ;
		}
		cout << endl;
	}
}

int main() {
	test();
	return 0;
}