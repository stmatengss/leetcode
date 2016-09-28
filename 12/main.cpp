#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
	string tab[3][10] = {
		{"","I","II","III","IV","V","VI","VII","VIII","IX"},
		{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
		{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
	}; 		
public:
	Solution(){
		
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
};

void test(){
	Solution t = Solution();
	cout<<t.intToRoman(900)<<endl;
	cout<<t.intToRoman(4)<<endl;
	cout<<t.intToRoman(1954)<<endl;
	cout<<t.intToRoman(2014)<<endl;
}

int main(){
	test();
	return 0;
}
