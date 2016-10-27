#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)return NULL;
        vector<int> vec(k);
        int i, j;
        ListNode* p = head;
        ListNode* pre = p;
        while (p) {
        	for (i = 0; i < k; i++) {
        		if (p == NULL) return head;
				vec[k-i-1] = p->val;
				p = p->next;
			}
			for (i = 0; i < k; i++) {
				pre->val = vec[i];
				pre = pre->next;
			}	
		}
		return head;			
    }
};

void print(ListNode* res) {
	while (res!=NULL) {
		cout<<res->val<<endl;
		res = res->next;
	}
}

void test(){
	vector<ListNode*> lists;
//	ListNode* head1 = NULL;
	ListNode* head1 = new ListNode(1);
	ListNode* p = head1;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(4);
//	p = p->next;
//	p->next = new ListNode(7);
//	p = p->next;
//	p->next = new ListNode(6);
	Solution t = Solution();
	auto a = t.reverseKGroup(head1, 1);
	print(a);
}

int main(){
	test();
	return 0;
}
