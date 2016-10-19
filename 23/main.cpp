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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<int,vector<int>,greater<int> > pq;
		for (auto i:lists) {
			while (i) {
				pq.push(i->val);
				i = i->next;
			}
		}
		if (pq.empty()) return NULL;
		ListNode* res = new ListNode(pq.top());
		pq.pop();
		ListNode* p = res;
		while (!pq.empty()) {
			p->next = new ListNode(pq.top());
			pq.pop();
			p = p->next;
		} 
		return res;
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
	ListNode* head1 = new ListNode(1);
	ListNode* p = head1;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(7);
	p = p->next;
	p->next = new ListNode(9);
	ListNode* head2 = new ListNode(3);
	p = head2;
	p->next = new ListNode(5);
	p = p->next;
	p->next = new ListNode(6);
	p = p->next;
	p->next = new ListNode(8);
	p = p->next;
	p->next = new ListNode(10);
	p = p->next;
	p->next = new ListNode(11);
	p = p->next;
	p->next = new ListNode(12);
	lists.push_back(head1);
	lists.push_back(head2);
	
	Solution t = Solution();
	auto a = t.mergeKLists(lists);
	print(a);
}

int main(){
	test();
	return 0;
}
