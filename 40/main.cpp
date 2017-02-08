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
    vector<int> size;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        candidates.push_back(-1);
        int counter = 1;
        for (int i = 0; i <= candidates.size() - 2; i ++ ) {
            if (candidates[i] != candidates[i + 1]) {
                size.push_back(counter);
                a.push_back(candidates[i]);
                counter = 0;
            }
            counter ++;
        }
        // a = vector<int>(candidates.begin(), candidates.end());
        b = vector<int>(1000, 0);
        dfs(target, 0, 0);
        return res;
    }
    void dfs(int target, int pos, int len) {
     // if (target < 0) return;
        for(int i = pos; i < a.size(); i ++ ) {
            int counter = 0;

            for(int j = 1; j <= size[i]; j ++ ) {
                counter += a[i];
                // cout << "j:" << j <<endl;
                if (target - counter < 0) break;
                b[len + j - 1] = a[i];
                if (target - counter == 0) {
                    res.push_back(vector<int>(b.begin(), b.begin() + len + j));
                    break;
                }
                dfs(target - counter, i + 1, len + j);
            }
     }
    }
};

void test() {
	vector<int> a({10, 1, 2, 7, 6, 1, 5});
	Solution t = Solution();
	for (auto i: t.combinationSum2(a, 8)) {
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