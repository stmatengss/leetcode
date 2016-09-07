#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int ptr1 = 0, ptr2 = 0;
		int ptr_max;
		int mid = (num1.size() + num2.size()) / 2 + 1;
		int pre = 0;                                             
		int i,j;
		for (i=20;i>=0;i--) {
			int jump = 1<<i;
			if ((jump & i) {
				if (nums1[ptr1] > nums2[ptr2]) {
					if (ptr1 + jump > nums1.size()) {
						ptr2 = ptr2 + jump + nums1.size() - ptr1;
						ptr1 = num1.size();
					} else {
						
					}
				} else {
					if (ptr2 + jump > nums1.size())
				}
			}
		}	
	}

};

void test(){

}

int main(){
	return 0;
}
