/*************************************************************************
    > File Name: 46/main.cpp
    > Author: stmatengss
    > Mail: stmatengss@163.com 
    > Created Time: Mon Feb  6 21:32:54 2017
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    typedef long long ll;

    const ll MOD = 1LL << 62;

    ll hash(string in) {
        sort(in.begin(), in.end());

        ll res = 0LL;
        for (auto ch: in) {
            res = (res * 131 + (ch - 'a' + 1)) % MOD;
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string> strs) {
        vector<vector<string>> res;
        map<ll, int> mp;
        for (auto str: strs) {
            int hash_code = hash(str);
            if (mp[hash_code] == 0) {
                mp[hash_code] = res.size() + 1;
                res.push_back(vector<string>());
            }
            // cout << hash_code << endl;
            res[mp[hash_code] - 1].push_back(str);
        }
        return res; 
    }
};

void test() {
	Solution t = Solution();
    std::vector<string> v({
        "eat", "tea", "tan", "ate", "nat", "bat"
    });
    auto res = t.groupAnagrams(v);	
    for (auto i: res) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
	test();
	return 0;
}