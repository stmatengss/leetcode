#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <algorithm>
#include <queue>
#include <limits>
#include <array>


using namespace std;

typedef vector<int> vec;


template<typename T>
void print(vector<T> a) {
	cout << "len:" << a.size() << endl;
	for(auto i:a) {
		cout<<i<<endl;	
	}
}

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> res;
    	int word_len = words[0].length();
    	int vec_len = words.size();
    	int s_len = s.length();
    	int res_len = vec_len * word_len;
    	if (res_len > s_len) {
    		return res;
    	}
    	map<string, int> mp;

    	vector<int> num(s_len, 0);
    	vector<int> word_inc(vec_len + 1, 0);
    	int counter = 1;
    	for (auto word: words) {
    		if(mp[word] == 0) {
    			mp[word] = counter;
    			counter ++;
    		}
    		word_inc[mp[word]] ++;
    	}
    	// print<int>(word_inc);
        for (int i = 0; i <= s_len - word_len; i ++ ) {
        	num[i] = mp[s.substr(i, word_len)];
        }
        // print<int>(num);
        for (int delta = 0; delta < word_len; delta ++ ) {
        	vector<int> word_count(vec_len + 1, 0);
        	counter = 0;
        	// cout << "d:" << delta << endl; 
        	for (int i = delta; i < res_len + delta; i += word_len ) {
	        	word_count[num[i]] ++;
	        	if (num[i] != 0) {
		        	if (word_count[num[i]] == word_inc[num[i]]) {
		        		counter += word_inc[num[i]];
		        	} else if (word_count[num[i]] == word_inc[num[i]] + 1) {
		        		counter -= word_inc[num[i]];
		        	}	
	        	}
	        	
	        }
	        int i, j;
 	        for (i = res_len + delta, j = delta; i <= s_len - word_len; i += word_len, j += word_len ) {
	        	// cout << counter << endl;
	        	if (counter == vec_len) {
	        		res.push_back(j);
	        	}
	        	int flag_r = num[i];
	        	int flag_l = num[j];
	        	if (flag_r != 0) {
		        	word_count[flag_r] ++;
		        	if (word_count[flag_r] == word_inc[flag_r]) {
		        		counter += word_inc[flag_r];
		        	} else if (word_count[flag_r] == word_inc[flag_r] + 1) {
		        		counter -= word_inc[flag_r];
		        	}
	        	}
	        	if (flag_l != 0) {
	        		word_count[flag_l] --;
		        	if (word_count[flag_l] == word_inc[flag_l] - 1) {
		        		counter -= word_inc[flag_l];
		        	} else if (word_count[flag_l] == word_inc[flag_l]) {
		        		counter += word_inc[flag_l];
		        	}
	        	}
	        	
        	}
        	// cout << counter << endl;
        	if (counter == vec_len) {
	        	res.push_back(j);
        	}
        }
        
        return res;
    }
};

void test() {
	Solution t = Solution();
	vector<string> input1({"foo", "bar"});
	// print<int>(t.findSubstring("barfoothefoobarman", input1)); //barfoothefoobarman
	vector<string> input2({"word","good","best","good"});
	// print<int>(t.findSubstring("wordgoodgoodgoodbestword", input2)); //barfoothefoobarman
	vector<string> input3({"aa","aa","aa",});
	print<int>(t.findSubstring("aaaaaaaa", input3)); //barfoothefoobarman
}

// "wordgoodgoodgoodbestword"
// ["word","good","best","good"]
// "aaaaaaaa"
// ["aa","aa","aa"]

int main(){
	test();
	return 0;
}
