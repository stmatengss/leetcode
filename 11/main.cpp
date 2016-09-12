#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int max_area = -1;
        while (left < right) {
        	int area = min(height[right], height[left]) * (right - left);
//        	cout<<area<<endl;
        	max_area = max(max_area, area);
        	if (height[right] < height[left]) {
        		right --;
			} else {
				left ++;
			}
		}
		return max_area;
    }
};

void test(){
	Solution t = Solution();
	vector<int> a;
	int aa[] = {1,1};
	a = vector<int>(aa, aa+2);
	cout<<(t.maxArea(a))<<endl;
}

int main(){
	test();
	return 0;
}
