/*************************************************************************
    > File Name: 4/main.cpp
    > Author: stmatengss
    > Mail: stmatengss@163.com 
    > Created Time: Thu Feb  2 13:53:17 2017
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (!nums1.size()) {
            if (nums2.size() & 1) {
                return nums2[nums2.size() / 2];
            } else {
                return (nums2[nums2.size() / 2 - 1] + nums2[nums2.size() / 2 ]) / 2.0;
            }
        }
        if (!nums2.size()) {
            if (nums1.size() & 1) {
                return nums1[nums1.size() / 2];
            } else {
                return (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2 ]) / 2.0;
            }
        }
        int len = nums1.size() + nums2.size();
        int half = (len + 1) / 2 - 1;
        int pos1 = 0, pos2 = 0;
        int p_half = half;

        while (p_half) {
        	int delta = p_half / 2;
            if (p_half == 1) delta = 1;
            p_half -= delta;
        }

        while (p_half) {
            int delta = p_half / 2;
            if (p_half == 1) delta = 1;
            delta = min(delta, min(nums2.size() - pos2 - 1, nums1.size() - pos2) );
            p_half -= delta;
            
            if (nums1[pos1] < nums2[pos2]) {
                if (pos1 + delta >= nums1.size()) {
                    pos1 = nums1.size() - 1;
                    pos2 += (delta - (nums1.size() - 1 - pos1));
                } else {
                    pos1 += delta; 
                }
               
            } else {
                if (pos2 + delta >= nums2.size()) {
                    pos2 = nums2.size() - 1;
                    pos1 += (delta - (nums2.size() - 1 - pos2));
                } else {
                    pos2 += delta;
                }
            }
            cout << pos1 << " " << pos2 << endl;
        }
        cout << "----" <<endl;
        if(len & 1) {
            return min(nums1[pos1], nums2[pos2]);
        } else {
            return (nums1[pos1] + nums2[pos2]) / 2.0;
        }
    }
};

void test() {
	vector<int> a({1, 3});
	vector<int> b({2, 4});
	Solution *test = new Solution();
	cout << test->findMedianSortedArrays(a, b) << endl; 
}

int main() {
	test();
	return 0;
}