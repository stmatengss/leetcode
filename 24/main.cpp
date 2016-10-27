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
    ListNode* swapPairs(ListNode* head) {
    	if (head == NULL)return NULL;
    	ListNode* first = head;
    	ListNode* second;
    	int tmp;
        while (first) {
        	second = first->next;
        	if (second == NULL) break;
        	tmp = first->val;
        	first->val = second->val;
        	second->val = tmp;
        	first = second->next;
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
	Solution t = Solution();
	auto a = t.swapPairs(head1);
	print(a);
}

int main(){
	test();
	return 0;
}
