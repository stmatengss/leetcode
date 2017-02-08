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
    int len1, len2;
    int MAX = 1<<30;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        len1 = nums1.size(), len2 = nums2.size();
        if (len & 1) {
            return find_kth(nums1, nums2, len / 2 + 1); 
        } else {
            return find_kth_kp1th(nums1, nums2, len / 2);
        }
    }
    double find_kth(vector<int>& nums1, vector<int>& nums2, int k) {
        int pos1 = 0, pos2 = 0;
        int delta;
        while (k) {

            if (pos1 >= len1) {
                return nums2[pos2 + k - 1];
            }

            if (pos2 >= len2) {
                return nums1[pos1 + k - 1];
            }

            if (k == 1) {
                // cout << pos1 << pos2 << min(nums1[pos1] , nums2[pos2]) << endl;
                return min(nums1[pos1] , nums2[pos2]);
            }
            delta = k / 2;
            k -= delta;

            int num1 = pos1 + delta - 1 >= len1 ? MAX : nums1[pos1 + delta - 1];
            int num2 = pos2 + delta - 1 >= len2 ? MAX : nums2[pos2 + delta - 1];


            if (num1 < num2) {
                pos1 += delta;
            } else {
                pos2 += delta;
            }
        }
        return -1;
    }
    double find_kth_kp1th(vector<int>& nums1, vector<int>& nums2, int k) {
        int pos1 = 0, pos2 = 0;
        int delta;
        while (k) {

            if (pos1 >= len1) {
                return (nums2[pos2 + k - 1] + nums2[pos2 + k]) / 2.0;
            }

            if (pos2 >= len2) {
                return (nums1[pos1 + k - 1] + nums1[pos1 + k]) / 2.0;
            }

            if (k == 1) {
                double res = (nums1[pos1] + nums2[pos2]) / 2.0;
                if (nums1[pos1] < nums2[pos2] && pos1 + 1 < len1) {
                    res = min(res, (nums1[pos1] + nums1[pos1 + 1]) / 2.0);
                } else if (nums1[pos1] > nums2[pos2] && pos2 + 1 < len2) {
                    res = min(res, (nums2[pos2] + nums2[pos2 + 1]) / 2.0);
                } 
                // cout << pos1 << pos2 << res << endl;
                return res;
            }
            delta = k / 2;
            k -= delta;

            int num1 = pos1 + delta - 1 >= len1 ? MAX : nums1[pos1 + delta - 1];
            int num2 = pos2 + delta - 1 >= len2 ? MAX : nums2[pos2 + delta - 1];


            if (num1 <= num2) {
                pos1 += delta;
            } else {
                pos2 += delta;
            }
        }
        return -1;
    }
};

void test() {
	vector<int> a({1, 2});
    vector<int> b({3, 4});
    vector<int> c({1, 1});
    vector<int> d({1, 2});
    vector<int> e({1});
	vector<int> f({2});
	Solution *test = new Solution();
    cout << test->findMedianSortedArrays(a, b) << endl; 
    cout << test->findMedianSortedArrays(c, d) << endl; 
	cout << test->findMedianSortedArrays(e, f) << endl; 
}

int main() {
	test();
	return 0;
}