#include<cstdio>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
private:
	string tab[3][10] = {
		{"","I","II","III","IV","V","VI","VII","VIII","IX"},
		{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
		{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
	};
	map<string, int>mp; 
	bool pending(string a, string b, int pos) {
		for (int i = b.length()-1, j = 0; i>=0; i--, j++) {
			if (b[i] != a[pos-j])
				return false;
		}
		return true;
	}
	int cmp(string a, int r, int pos) {
		for (int i = 1; i<=9; i++) {
			if (pending(a, tab[r][i], pos))
				return i;
		}
		return 0;
	}		
public:
	Solution(){
//		for (int i=1; i<=3999; i++) {
//			mp[intToRoman(i)] = i;
//		}
	} 
	~Solution(){
	}
    string intToRoman(int num) {
    	string res = ""; 
    	for (int i=0; i<=2 && num; i++) {
    		res = tab[i][num%10] + res;
    		num /= 10;
		}  
		for (int i=0; i< num; i++) {
			res = "M" + res;
		} 
		return res;
    }
    int romanToInt(string s) {
    	int ptr = s.length() - 1;
    	int round = 0;
    	int res = 0;
    	int d = 1;
        while ( ptr>=0 ) {
        	int del = cmp(s, round, ptr);
        	res += del * d;
        	d *= 10;
        	ptr -= tab[round][del].length();
        	round++;
        	if (round == 3)
        		break;
		}	
		res += ptr * d;
		return res + 1000;
    }
};

//class Solution {
//private:
//	string tab[3][10] = {
//		{"","I","II","III","IV","V","VI","VII","VIII","IX"},
//		{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
//		{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
//	};
//	map<string, int>mp; 		
//public:
//	Solution(){
//		for (int i=1; i<=3999; i++) {
//			mp[intToRoman(i)] = i;
//		}
//	} 
//	~Solution(){
//	}
//    string intToRoman(int num) {
//    	string res = ""; 
//    	for (int i=0; i<=2 && num; i++) {
//    		res = tab[i][num%10] + res;
//    		num /= 10;
//		}  
//		for (int i=0; i< num; i++) {
//			res = "M" + res;
//		} 
//		return res;
//    }
//    int romanToInt(string s) {
//        return mp[s];
//    }
//};

void test(){
	Solution t = Solution();
	cout<<t.intToRoman(900)<<endl;
	cout<<t.intToRoman(4)<<endl;
	cout<<t.intToRoman(1954)<<endl;
	cout<<t.intToRoman(2014)<<endl;
	cout<<t.romanToInt("CM")<<endl;
	cout<<t.romanToInt("IV")<<endl;
	cout<<t.romanToInt("MCMLIV")<<endl;
	cout<<t.romanToInt("MMXIV")<<endl;
}

int main(){
	test();
	return 0;
}
